
#include <string>
#include "rule.h"



int rule::getId() const {
    return id;
}

void rule::setId(int id) {
    rule::id = id;
}


const string &rule::getCondition() const {
    return condition;
}

void rule::setCondition(const string &condition) {
    rule::condition = condition;
}

const list<workflow> &rule::getSuccessor() const {
    return successor;
}

void rule::setSuccessor(const list<workflow> &successor) {
    rule::successor = successor;
}

rule::rule(int id, const string &predecessor, const string &condition, const list<workflow> &successor) : id(id),
                                                                                                          predecessor(
                                                                                                                  predecessor),
                                                                                                          condition(
                                                                                                                  condition),
                                                                                                          successor(
                                                                                                                  successor) {}

const string &rule::getPredecessor() const {
    return predecessor;
}

void rule::setPredecessor(const string &predecessor) {
    rule::predecessor = predecessor;
}
