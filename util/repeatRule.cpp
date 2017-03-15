

#include "repeatRule.h"
#include <iostream>
void repeatRule::apply() {
    std::cout<< "[" <<this->operationType<<"]" << "[" <<this->direction<< "]" << "[";
    for (auto i: this->params)
        std::cout << i << ' ';
    std::cout<<"]"<<"["<<this->target<<"]"<<std::endl;
}


const std::string &repeatRule::getTarget() const {
    return target;
}

void repeatRule::setTarget(const std::string &target) {
    repeatRule::target = target;
}

const std::string &repeatRule::getDirection() const {
    return direction;
}

void repeatRule::setDirection(const std::string &direction) {
    repeatRule::direction = direction;
}

const std::vector<std::string> &repeatRule::getParams() const {
    return params;
}

void repeatRule::setParams(const std::vector<std::string> &params) {
    repeatRule::params = params;
}

repeatRule::repeatRule(const std::string &target, const std::string &direction,
                       const std::vector<std::string> &params) : generalRule("repeat"), target(target),
                                                                 direction(direction), params(params) {}

