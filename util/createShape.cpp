//
// Created by mashenjun on 13-3-17.
//

#include "createShape.h"
#include <iostream>
void createShape::apply() {
    std::cout<< "[" <<this->operationType<<"]" << "[" <<this->param<< "]" <<std::endl;
}

const std::string &createShape::getParam() const {
    return param;
}

void createShape::setParam(const std::string &param) {
    createShape::param = param;
}


bool createShape::isTerminal() const {
    return terminal;
}

void createShape::setTerminal(bool terminal) {
    createShape::terminal = terminal;
}

createShape::createShape( const std::string &param, bool terminal) : generalRule(
        "create_shape"), param(param), terminal(terminal) {}




