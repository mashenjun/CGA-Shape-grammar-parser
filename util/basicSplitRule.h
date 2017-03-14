

#ifndef CGA_SHAPE_BASICSPLITRULE_H
#define CGA_SHAPE_BASICSPLITRULE_H

#include <vector>
#include "generalRule.h"


class basicSplitRule: public generalRule {
private:
    std::vector<std::string> targets;
    std::string direction;
    std::vector<std::string> params;

public:
    void apply() override;

    const std::vector<std::string> &getTargets() const;

    basicSplitRule(const std::vector<std::string> &targets, const std::string &direction,
                   const std::vector<std::string> &params);

    const std::string &getDirection() const;

    void setDirection(const std::string &direction);

    const std::vector<std::string> &getParams() const;

    void setParams(const std::vector<std::string> &params);

    basicSplitRule(const std::string &target, const std::string &direction, const std::vector<std::string> &params);
};


#endif //CGA_SHAPE_BASICSPLITRULE_H
