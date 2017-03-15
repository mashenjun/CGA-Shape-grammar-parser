

#include "basicSplitRule.h"
#include <iostream>
#include "createShape.h"

void basicSplitRule::apply() {
    std::cout<< "[" <<this->operationType<<"]" << "[" <<this->direction<< "]" <<"[";
    for (auto i: this->params)
        std::cout << i << ' ';
    std::cout<<"]"<<"[";
    for (auto i: this->targets)
        std::cout << i << ' ';
    std::cout <<"]"<<std::endl;
}

const std::string &basicSplitRule::getDirection() const {
    return direction;
}

void basicSplitRule::setDirection(const std::string &direction) {
    basicSplitRule::direction = direction;
}

const std::vector<std::string> &basicSplitRule::getParams() const {
    return params;
}

void basicSplitRule::setParams(const std::vector<std::string> &params) {
    basicSplitRule::params = params;
}


const std::vector<std::string> &basicSplitRule::getTargets() const {
    return targets;
}

basicSplitRule::basicSplitRule( const std::vector<std::string> &targets,
                               const std::string &direction, const std::vector<std::string> &params) : generalRule(
        "basic_split"), targets(targets), direction(direction), params(params) {}
