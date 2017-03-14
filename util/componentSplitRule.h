

#ifndef CGA_SHAPE_COMPONENTSPLITRULE_H
#define CGA_SHAPE_COMPONENTSPLITRULE_H
#include "generalRule.h"

class componentSplitRule: public generalRule {
private:
    std::string target;
    std::string param;

public:
    const std::string &getTarget() const;

    void setTarget(const std::string &target);

    const std::string &getParam() const;

    void setParam(const std::string &param);

    componentSplitRule(const std::string &target, const std::string &param);

    void apply() override;

};


#endif //CGA_SHAPE_COMPONENTSPLITRULE_H
