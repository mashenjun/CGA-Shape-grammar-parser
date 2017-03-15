

#include "componentSplitRule.h"
#include <iostream>
void componentSplitRule::apply() {
    std::cout<< "[" <<this->operationType<<"]" << "[" <<this->param<< "]" <<"["<<this->target <<"]"<<std::endl;
}


const std::string &componentSplitRule::getTarget() const {
    return target;
}

void componentSplitRule::setTarget(const std::string &target) {
    componentSplitRule::target = target;
}

const std::string &componentSplitRule::getParam() const {
    return param;
}

void componentSplitRule::setParam(const std::string &param) {
    componentSplitRule::param = param;
}

componentSplitRule::componentSplitRule(const std::string &target,
                                       const std::string &param) : generalRule("component_split"), target(target),
                                                                   param(param) {}
