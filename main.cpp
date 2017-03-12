#include <iostream>
#include "parser/y_io_2.h"
#include <stdio.h>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <regex>
#include <string>
#include <typeinfo>

using std::regex;
using std::string;


std::vector<std::string> split( std::string& text,  std::string& delims)
{
    std::vector<std::string> tokens;
    std::string token;
    size_t pos = 0;
    while ((pos = text.find(delims)) != std::string::npos) {
        token = text.substr(0, pos);
        if(token.size()>0){
            tokens.push_back(token);
            text.erase(0, pos + delims.length());
        }
    }
    if (text.size()>0) {
        tokens.push_back(text);
    };

    return tokens;
}


int main() {
//    std::cout << GetCurrentWorkingDir() << std::endl;

    std::vector<std::string> rules;
    std::string newline = "\n";
    char*s=yIo2::ReadTextFile("test_rules.txt");
    std::string str(s);
    size_t pos = 0;
    std::string token;
    std::regex rgx("\\d+:{1}\\ {1}");
    std::string ruleBreaker = "-->";
    std::string conditionBreaker = ":";
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
        std::vector<std::string> tokens;
        int id = i+1;
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
        std::cout << '[' << tokens.size() << ']' << std::endl;

        if(tokens.size()>0){
//            process the left part of rules.
            std::string predecessor ;
            std::string condition ;
            if (tokens[0].find(conditionBreaker) != std::string::npos) {
                std::vector<std::string> temp = split(tokens[0],conditionBreaker);
                predecessor = temp[0];
                condition = temp[1];
            }
            else {
                predecessor = tokens[0];
                condition = "NAN";
            }


        }


    }
    std::cout << "END!!!" << std::endl;
    return 0;
}