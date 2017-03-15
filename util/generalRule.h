//
// Created by mashenjun on 13-3-17.
//

#ifndef CGA_SHAPE_GENERALRULE_H
#define CGA_SHAPE_GENERALRULE_H

#include <string>
#include <map>

class generalRule {
protected:
    std::string operationType ;
public:
    virtual void apply()=0;

    generalRule(const std::string &operationType);

    const std::string &getOperationType() const;

    void setOperationType(const std::string &operationType);

};


#endif //CGA_SHAPE_GENERALRULE_H
