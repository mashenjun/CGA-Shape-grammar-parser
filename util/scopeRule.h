
#include <tuple>
#ifndef CGA_SHAPE_SCOPERULE_H
#define CGA_SHAPE_SCOPERULE_H

#include "../shape/shape.h"
#include "generalRule.h"

class scopeRule: public generalRule {
private:
    tuple<std::string,std::string,std::string> t ;
    tuple<std::string,std::string,std::string> s;
    std::string rx;
    std::string ry;
    std::string rz;
    std::string target ;
public:
    scopeRule(const string &name);

    const tuple<string, string, string> &getT() const;

    void setT(const tuple<string, string, string> &t);

    const tuple<string, string, string> &getS() const;

    void setS(const tuple<string, string, string> &s);

    const string &getRx() const;

    void setRx(const string &rx);

    const string &getRy() const;

    void setRy(const string &ry);

    const string &getRz() const;

    void setRz(const string &rz);

    const string &getTarget() const;

    void setTarget(const string &target);

    void apply() override;

};


#endif //CGA_SHAPE_SCOPERULE_H
