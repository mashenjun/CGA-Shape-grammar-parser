//
// Created by mashenjun on 14-3-17.
//

#ifndef CGA_SHAPE_NESTEDBASICSPLITRULE_H
#define CGA_SHAPE_NESTEDBASICSPLITRULE_H

#include <vector>
#include <memory>
#include "generalRule.h"

class nestedBasicSplitRule:public generalRule{
private:
    std::vector<std::shared_ptr<generalRule>> targets;
    std::string direction;
    std::vector<std::string> params;

public:
    void apply() override;

    const std::vector<std::shared_ptr<generalRule>> &getTargets() const;

    void setTargets(const std::vector<std::shared_ptr<generalRule>> &targets);

    const std::string &getDirection() const;

    void setDirection(const std::string &direction);

    const std::vector<std::string> &getParams() const;

    void setParams(const std::vector<std::string> &params);

    nestedBasicSplitRule(const std::vector<std::shared_ptr<generalRule>> &targets, const std::string &direction,
                         const std::vector<std::string> &params);
};


#endif //CGA_SHAPE_NESTEDBASICSPLITRULE_H
