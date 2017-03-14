

#include "repeatRule.h"

void repeatRule::apply() {

}

repeatRule::repeatRule(const std::string &target, const std::string &direction, const std::vector<std::string> &params)
        : target(target), direction(direction), params(params) {}

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

