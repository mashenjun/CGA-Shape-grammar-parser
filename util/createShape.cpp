//
// Created by mashenjun on 13-3-17.
//

#include "createShape.h"

void createShape::apply() {

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

createShape::createShape(const std::string &param, bool terminal) : param(param), terminal(terminal) {}



