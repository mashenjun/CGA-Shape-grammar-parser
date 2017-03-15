//
// Created by mashenjun on 14-3-17.
//

#include "nestedBasicSplitRule.h"
#include <iostream>
void nestedBasicSplitRule::apply() {
   return;
}


const std::string &nestedBasicSplitRule::getDirection() const {
    return direction;
}

void nestedBasicSplitRule::setDirection(const std::string &direction) {
    nestedBasicSplitRule::direction = direction;
}

const std::vector<std::string> &nestedBasicSplitRule::getParams() const {
    return params;
}

void nestedBasicSplitRule::setParams(const std::vector<std::string> &params) {
    nestedBasicSplitRule::params = params;
}


const std::vector<std::shared_ptr<generalRule>> &nestedBasicSplitRule::getTargets() const {
    return targets;
}

void nestedBasicSplitRule::setTargets(const std::vector<std::shared_ptr<generalRule>> &targets) {
    nestedBasicSplitRule::targets = targets;
}

nestedBasicSplitRule::nestedBasicSplitRule(const std::vector<std::shared_ptr<generalRule>> &targets,
                                           const std::string &direction, const std::vector<std::string> &params)
        : generalRule("nested_basic_split"), targets(targets), direction(direction), params(params) {}
