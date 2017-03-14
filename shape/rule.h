

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
        std::list<workflow> successor; // steps


public:
    rule(int id, const string &predecessor, const string &condition, const list<workflow> &successor);

    int getId() const;

    void setId(int id);


    const string &getCondition() const;

    void setCondition(const string &condition);

    const list<workflow> &getSuccessor() const;

    void setSuccessor(const list<workflow> &successor);

    const string &getPredecessor() const;

    void setPredecessor(const string &predecessor);
};


#endif //CGA_SHAPE_RULE_H
