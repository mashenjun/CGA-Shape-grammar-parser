

#ifndef CGA_SHAPE_RULE_H
#define CGA_SHAPE_RULE_H

#include <list>
#include <string>

#include "shape.h"
#include "nonterminalShape.h"
#include "terminalShape.h"
#include "../util/generalRule.h"
#include "workflow.h"
class rule {
    private:
        int id;
        std::string predecessor;
        std::string condition ;
        std::vector<workflow> successor; // steps


public:
    rule(int id, const string &predecessor, const string &condition, const vector<workflow> &successor);

    int getId() const;

    void setId(int id);

    const string &getCondition() const;

    void setCondition(const string &condition);

    const vector<workflow> &getSuccessor() const;

    const string &getPredecessor() const;

    void setPredecessor(const string &predecessor);

    void process();

    void setSuccessor(const vector<workflow> &successor);
};


#endif //CGA_SHAPE_RULE_H
