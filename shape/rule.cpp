
#include <string>
#include "rule.h"





int rule::getId() const {
    return id;
}

void rule::setId(int id) {
    rule::id = id;
}

const nonterminalShape &rule::getPredecessor() const {
    return predecessor;
}

void rule::setPredecessor(const nonterminalShape &predecessor) {
    rule::predecessor = predecessor;
}

const list<shape> &rule::getSuccessor() const {
    return successor;
}

void rule::setSuccessor(const list<shape> &successor) {
    rule::successor = successor;
}


bool rule::isCondition() const {
    return condition;
}

void rule::setCondition(bool condition) {
    rule::condition = condition;
}

rule::rule(int id, const nonterminalShape &predecessor, bool condition, const list<shape> &successor) : id(id),
                                                                                                        predecessor(
                                                                                                                predecessor),
                                                                                                        condition(
                                                                                                                condition),
                                                                                                        successor(
                                                                                                                successor) {}


