//
// Created by mashenjun on 12-3-17.
//

#ifndef CGA_SHAPE_RULE_H
#define CGA_SHAPE_RULE_H

#include <list>
#include <string>

#include "shape.h"
#include "nonterminalShape.h"
#include "terminalShape.h"

class rule {
    private:
        int id;
        nonterminalShape predecessor;
        bool condition = true;
        std::list<shape> successor;

public:
    rule(int id, const nonterminalShape &predecessor, bool condition, const list<shape> &successor);

    int getId() const;

    void setId(int id);

    const nonterminalShape &getPredecessor() const;

    void setPredecessor(const nonterminalShape &predecessor);

    const list<shape> &getSuccessor() const;

    void setSuccessor(const list<shape> &successor);

    bool isCondition() const;

    void setCondition(bool condition);
};


#endif //CGA_SHAPE_RULE_H
