

#include "componentSplitRule.h"

void componentSplitRule::apply() {

}

componentSplitRule::componentSplitRule(const std::string &target, const std::string &param) : target(target),
                                                                                              param(param) {}

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
