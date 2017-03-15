#include <iostream>
#include <stdio.h>
#include <random>
#include <memory>
#include <vector>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <regex>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <typeinfo>

#include "shape/terminalShape.h"
#include "shape/nonterminalShape.h"
#include "parser/y_io_2.h"
#include "shape/workflow.h"
#include "shape/rule.h"
#include "util/createShape.h"
#include "util/scopeRule.h"
#include "util/basicSplitRule.h"
#include "util/nestedBasicSplitRule.h"
#include "util/componentSplitRule.h"
#include "util/repeatRule.h"

using std::regex;
using std::string;


std::regex rgx("\\d+:{1}\\ {1}");
std::regex terminalShapeRgx("I{1}\\({1}.+\\){1}");
std::regex scopeRuleRgx("(OP-S|OP-T|OP-Rx|OP-Ry|OP-Rz){1}\\({1}");
std::regex basicSplitRuleRgx("(OP-Subdiv){1}");
std::regex componentSplitRuleRgx("(OP-Comp){1}");
std::regex repeatSplitRuleRgx("(OP-Repeat){1}");
std::string ruleBreaker = "-->";
std::string conditionBreaker = ":";
std::string probabilityBreaker = ":";
std::string paramBreaker = ",";
std::string targetBreaker = ",";
std::string operationBreaker = "OP-";
std::string objectNameStartBreaker = "(\"";
std::string objectNameEndBreaker = "\")";
std::string openbracket = "{";
std::string closebracket = "}";
std::string stopWords = " \t\n\r";
std::string childKeyWord = "childnode";

std::vector<std::string> split( std::string& text,  std::string& delims)
{
    std::vector<std::string> tokens;
    std::string token;
    size_t pos = 0;
    while ((pos = text.find(delims)) != std::string::npos) {
        token = text.substr(0, pos);
        if(token.size()>0){
            tokens.push_back(token);
        }
        text.erase(0, pos + delims.length());
    }
    if (text.size()>0) {
        tokens.push_back(text);
    };

    return tokens;
}

string separate(string str)
{
    size_t endpos = str.find_last_not_of(" \t\n\r");
    if (string::npos != endpos)
    {
        str = str.substr(0, endpos + 1);
    }

    size_t startpos = str.find_first_not_of(" \t\n\r");
    if (string::npos != startpos)
    {
        str = str.substr(startpos);
    }

    return str;
}

string removeQuotes(string str)
{
    size_t endpos = str.find_last_not_of("\"");
    if (string::npos != endpos)
    {
        str = str.substr(0, endpos + 1);
    }

    size_t startpos = str.find_first_not_of("\"");
    if (string::npos != startpos)
    {
        str = str.substr(startpos);
    }

    return str;
}

int findBracketsPos(std::string text, int index, std::stack<int> &findBrackectList ,std::queue<std::pair<int,int>> &bracketPairList ){

    while (index<text.size()){
        if(text[index]=='{'){
            findBrackectList.push(index);
            index = findBracketsPos(text,index+1,findBrackectList,bracketPairList) ;
        }
        else if(text[index]=='}'){
            if (text[findBrackectList.top()]=='{'){
                std::pair<int,int> bp = {findBrackectList.top(),index};
                bracketPairList.push(bp);
                findBrackectList.pop();
            }

            return index+1;
        }
        else {
            ++index;
        }
    }
    return index;
}

int findOpBracketsPos(std::string text, int index, std::stack<int> &findBrackectList ,std::queue<std::pair<int,int>> &bracketPairList ){
    while (index<text.size()){
        if(text[index]=='('){
            findBrackectList.push(index);
            index = findOpBracketsPos(text,index+1,findBrackectList,bracketPairList) ;
        }
        else if(text[index]==')'){
            if (text[findBrackectList.top()]=='('){
                std::pair<int,int> bp = {findBrackectList.top(),index};
                bracketPairList.push(bp);
                findBrackectList.pop();
            }

            return index+1;
        }
        else {
            ++index;
        }
    }
    return index;
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

workflow generateWF(std::string successor, float prob){
    // create shape
//    std::vector<generalRule> v;
    std::vector<std::shared_ptr<generalRule>> v;
    if (successor.find(operationBreaker) == string::npos){
        if (std::regex_search(successor,terminalShapeRgx)){
            size_t posStart = successor.find(objectNameStartBreaker);
            size_t posEnd = successor.find(objectNameEndBreaker);
            string objName = successor.substr(posStart + 2, posEnd - posStart - 2);
            createShape terminalShape = createShape(objName,true);
//            std::vector<std::shared_ptr<generalRule>> v{ std::make_shared<createShape>(terminalShape)};
//            v.push_back(terminalShape);
            v.push_back(std::make_shared<createShape>(terminalShape));
        }
        else {
            std::string objName = successor;
            if (successor.find(stopWords) == string::npos){
                std::string objName = separate(successor);
            }
            createShape nonterminalShape = createShape(objName, false);
//            v.push_back(nonterminalShape);
            v.push_back(std::make_shared<createShape>(nonterminalShape));
//            workflow result = workflow(prob,v);
//            return result;
        }
    }
    //all different rules with brakets
    if(successor.find(operationBreaker) != string::npos && successor.find(openbracket)!=string::npos){
        std::stack<int> fbl;
        std::queue<std::pair<int,int>> bpl;
        findBracketsPos(successor,0,fbl,bpl);
        std::stack<std::string> temp;

        int tracker=0 ;

        while (bpl.size()>0){
            int ob = bpl.front().first;
            int cb = bpl.front().second;

            if (successor.substr(0,bpl.front().first-0).find_last_of("{}|")!=string::npos){
                tracker = (int)(successor.find_last_of("{}|",bpl.front().first-1)+1);
            }
            else {
                tracker = 0;
            }
            std::string op_str = successor.substr(tracker,ob-tracker);
            std::string target = successor.substr(ob+1,cb-ob-1);
            if (target.find(openbracket)!=string::npos){
                std::string op_tg = op_str+'{'+target+'}';
//                generalRule child = v.back();
                std::shared_ptr<generalRule> child = (shared_ptr<generalRule> &&) v.back();
                v.pop_back();
                replaceAll(target,temp.top(),childKeyWord);

                std::stack<int> fopbl;
                std::queue<std::pair<int,int>> opbpl;
                findOpBracketsPos(op_str,0,fopbl,opbpl);
                std::string parm_str = op_str.substr(opbpl.front().first+1,opbpl.front().second-opbpl.front().first-1);
                std::vector<std::string> params = split(parm_str,paramBreaker);
                std::string direction = removeQuotes(params[0]);
                params.erase(params.begin());
                std::vector<std::string> targets = split(target,targetBreaker);
//                std::vector<generalRule> newtarget;
                std::vector<std::shared_ptr<generalRule>> newtarget;
                for(std::string item: targets){
                    if (item.find(childKeyWord)!=string::npos){
                        newtarget.push_back(child);
                    }else{
                        createShape csp = createShape(item,false);
//                        newtarget.push_back(csp);
                        newtarget.push_back(std::make_shared<createShape>(csp));

                    }
                }
                nestedBasicSplitRule nbsr = nestedBasicSplitRule(newtarget,direction,params);
//                v.push_back(nbsr);
                v.push_back(std::make_shared<nestedBasicSplitRule>(nbsr));
                temp.push(op_tg);
            }
            else {
                std::string op_tg = op_str+'{'+target+'}';
                temp.push(op_tg);
                std::stack<int> fopbl;
                std::queue<std::pair<int,int>> opbpl;
                findOpBracketsPos(op_str,0,fopbl,opbpl);
                if (std::regex_search (op_str,scopeRuleRgx)){
                    scopeRule spr = scopeRule(target);
                    int tracker_opname = 0;
                    while(opbpl.size()>0){
                        std::string op_name = op_str.substr(tracker_opname,opbpl.front().first-tracker_opname);
                        std::string parm_str = op_str.substr(opbpl.front().first+1,opbpl.front().second-opbpl.front().first-1);
                        if(op_name.find("OP-S")!=string::npos){
                            std::vector<std::string> params = split(parm_str,paramBreaker);
                            spr.setS(std::make_tuple(params[0],params[1],params[2]));
                        }
                        else if(op_name.find("OP-T")!=string::npos){
                            std::vector<std::string> params = split(parm_str,paramBreaker);
                            spr.setT(std::make_tuple(params[0],params[1],params[2]));
                        }
                        else if(op_name.find("OP-Rx")!=string::npos){
                            spr.setRx(parm_str);
                        }
                        else if(op_name.find("OP-Ry")!=string::npos){
                            spr.setRy(parm_str);
                        }
                        else if(op_name.find("OP-Rz")!=string::npos){
                            spr.setRz(parm_str);
                        }

                        tracker_opname = opbpl.front().second+1;
                        opbpl.pop();
                    }
//                    v.push_back(spr);
                    v.push_back(std::make_shared<scopeRule>(spr));
                }
                else if(std::regex_search (op_str,basicSplitRuleRgx)){
                    std::string parm_str = op_str.substr(opbpl.front().first+1,opbpl.front().second-opbpl.front().first-1);
                    std::vector<std::string> params = split(parm_str,paramBreaker);
                    std::string direction = removeQuotes(params[0]);
                    params.erase(params.begin());
                    basicSplitRule bsr = basicSplitRule(split(target,targetBreaker),direction,params);
//                    v.push_back(bsr);
                    v.push_back(std::make_shared<basicSplitRule>(bsr));
                }
                else if(std::regex_search (op_str,componentSplitRuleRgx)){
                    std::string parm_str = removeQuotes(op_str.substr(opbpl.front().first+1,opbpl.front().second-opbpl.front().first-1));
                    componentSplitRule csr = componentSplitRule(target,parm_str);
//                    v.push_back(csr);
                    v.push_back(std::make_shared<componentSplitRule>(csr));
                }
                else if (std::regex_search (op_str,repeatSplitRuleRgx)){
                    std::string parm_str = op_str.substr(opbpl.front().first+1,opbpl.front().second-opbpl.front().first-1);
                    std::vector<std::string> params = split(parm_str,paramBreaker);
                    std::string direction = removeQuotes(params[0]);
                    params.erase(params.begin());
                    repeatRule rpr = repeatRule(target,direction,params);
//                    v.push_back(rpr);
                    v.push_back(std::make_shared<repeatRule>(rpr));
                }
            }
            bpl.pop();
        }

    }
    if(successor.find(operationBreaker) != string::npos && successor.find(openbracket)==string::npos){
        std::stack<int> fopbl;
        std::queue<std::pair<int,int>> opbpl;
        findOpBracketsPos(successor,0,fopbl,opbpl);
            scopeRule spr = scopeRule("");
            int tracker_opname = 0;
            while(opbpl.size()>0){
                std::string op_name = successor.substr(tracker_opname,opbpl.front().first-tracker_opname);
                std::string parm_str = successor.substr(opbpl.front().first+1,opbpl.front().second-opbpl.front().first-1);
                if(op_name.find("OP-S")!=string::npos){
                    std::vector<std::string> params = split(parm_str,paramBreaker);
                    spr.setS(std::make_tuple(params[0],params[1],params[2]));
                }
                else if(op_name.find("OP-T")!=string::npos){
                    std::vector<std::string> params = split(parm_str,paramBreaker);
                    spr.setT(std::make_tuple(params[0],params[1],params[2]));
                }
                else if(op_name.find("OP-Rx")!=string::npos){
                    spr.setRx(parm_str);
                }
                else if(op_name.find("OP-Ry")!=string::npos){
                    spr.setRy(parm_str);
                }
                else if(op_name.find("OP-Rz")!=string::npos){
                    spr.setRz(parm_str);
                }
                else if(op_name.find("I")!=string::npos){
                    spr.setTarget(removeQuotes(parm_str));
                }
                tracker_opname = opbpl.front().second+1;
                opbpl.pop();
            }
//            v.push_back(spr);
        v.push_back(std::make_shared<scopeRule>(spr));
    }

    workflow result = workflow(prob,v);
    return result;
}



int main() {

//    std::cout << GetCurrentWorkingDir() << std::endl;
//    std::list<std::string> scopeRuleKeyWords = {"OP-S","OP-T","OP-Rx","OP-Ry","OP-Rz"};

//    std::list<terminalShape> terminalShaps = {} ;
//    std::list<nonterminalShape> nonterminalShape = {} ;
    std::stack<std::string> operations;
    std::vector<std::string> rules;
    std::vector<rule> rulesbook;
    std::string newline = "\n";
    char*s=yIo2::ReadTextFile("test_rules2.txt");
    std::string str(s);
    size_t pos = 0;
//    std::string token;
//    std::regex rgx("\\d+:{1}\\ {1}");
//    std::string ruleBreaker = "-->";
//    std::string conditionBreaker = ":";
//    std::string probabilityBreaker = ":";
//    std::string operationBreaker = "OP-";
//    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    std::sregex_token_iterator iter(str.begin(),
                                    str.end(),
                                    rgx,
                                    -1);
    std::sregex_token_iterator end;
    for ( ; iter != end; ++iter){
        if ((iter->str()).size()>0){

            rules.push_back(iter->str());
        }
//        std::cout << (iter->str()).size()  << std::endl;
//        std::cout << "[" <<*iter << "]\n";
    }
//    while ((pos = str.find(delimiter)) != std::string::npos) {
//        token = str.substr(0, pos);
//        std::cout << token << " el "<< std::endl;
//        str.erase(0, pos + delimiter.length());
//    }
    for (int i = 0; i < rules.size(); ++i) {
        //            process a single rule
        std::vector<std::string> tokens;
        int id = i+1;
        std::string predecessor ;
        std::string condition ;
        std::string successor ;
        std::vector<workflow> workflows;
        std::string rule_str = rules[i];
//        std::string token = rule_str.substr(0, rule_str.find(delimiter));
//        while ((pos = rule_str.find(ruleBreaker)) != std::string::npos) {
//            token = rule_str.substr(0, pos);
////            if(token.back()=='\n'){
////                token.erase(std::remove(token.begin(), token.end(), '\n'), token.end());
////            }
//            std::cout << '[' << token << ']' << std::endl;
//            tokens.push_back(token);
//            rule_str.erase(0, pos + ruleBreaker.length());
//        }
////        if(rule_str.find('\n') != string::npos){
////            rule_str.erase(std::remove(rule_str.begin(), rule_str.end(), '\n'), rule_str.end());
////        }
//        std::cout << '[' << rule_str << ']' << std::endl;
//        tokens.push_back(rule_str);
        tokens = split(rule_str,ruleBreaker);
//        std::cout << '[' << rule_str << ']' << std::endl;

        if(tokens.size()>0){

//            process the left part of rules.
            if (tokens[0].find(conditionBreaker) != std::string::npos) {
                std::vector<std::string> temp = split(tokens[0],conditionBreaker);
                predecessor = temp[0];
                condition = separate(temp[1]);
            }
            else {
                predecessor = tokens[0];
                condition = "NAN";
            }
//            process the right part may be multiple bodies

            for (int j = 1; j <tokens.size() ; ++j) {
                if(tokens[j].find(probabilityBreaker) != std::string::npos){
                    std::vector<std::string> temp = split(tokens[j],probabilityBreaker);
                    successor = temp[0];
                    workflows.push_back(generateWF(temp[0],strtof((temp[1]).c_str(),0)));
//                    probability.push_back(strtof((temp[1]).c_str(),0));
                }
                else {
                    successor = tokens[j];
                    workflows.push_back(generateWF(successor,1.0));
//                    probability.push_back(1.0);
                }

            }


        }
        rule signleRule = rule(id,predecessor,condition,workflows);
        rulesbook.push_back(signleRule);

    }
    for (int k = 0; k < rulesbook.size(); ++k) {
        rulesbook[k].process();
    }

    std::cout << "END!!!" << std::endl;
    return 0;
}