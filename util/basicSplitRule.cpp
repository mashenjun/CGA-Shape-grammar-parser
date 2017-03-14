

#include "basicSplitRule.h"
#include "createShape.h"

void basicSplitRule::apply() {
    return ;
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

basicSplitRule::basicSplitRule(const std::vector<std::string> &targets, const std::string &direction,
                               const std::vector<std::string> &params) : targets(targets), direction(direction),
                                                                         params(params) {}

const std::vector<std::string> &basicSplitRule::getTargets() const {
    return targets;
}
