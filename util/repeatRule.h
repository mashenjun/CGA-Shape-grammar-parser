

#ifndef CGA_SHAPE_REPEATRULE_H
#define CGA_SHAPE_REPEATRULE_H

#include <vector>
#include "generalRule.h"

class repeatRule: public generalRule {
private:
    std::string target;
    std::string direction;
    std::vector<std::string> params;
public:
    const std::string &getTarget() const;

    void setTarget(const std::string &target);

    const std::string &getDirection() const;

    void setDirection(const std::string &direction);

    const std::vector<std::string> &getParams() const;

    void setParams(const std::vector<std::string> &params);

    repeatRule(const std::string &target, const std::string &direction,
               const std::vector<std::string> &params);

    void apply() override;



};


#endif //CGA_SHAPE_REPEATRULE_H
