
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

const string &rule::getPredecessor() const {
    return predecessor;
}

void rule::setPredecessor(const string &predecessor) {
    rule::predecessor = predecessor;
}

void rule::process (){
    for (int i = 0; i <this->successor.size() ; ++i) {
        successor[i].process();
    }
}

rule::rule(int id, const string &predecessor, const string &condition, const vector<workflow> &successor) : id(id),
                                                                                                            predecessor(
                                                                                                                    predecessor),
                                                                                                            condition(
                                                                                                                    condition),
                                                                                                            successor(
                                                                                                                    successor) {}

const vector<workflow> &rule::getSuccessor() const {
    return successor;
}

void rule::setSuccessor(const vector<workflow> &successor) {
    rule::successor = successor;
};
