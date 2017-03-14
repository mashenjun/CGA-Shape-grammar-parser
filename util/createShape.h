//
// Created by mashenjun on 13-3-17.
//

#ifndef CGA_SHAPE_CREATESHAPE_H
#define CGA_SHAPE_CREATESHAPE_H
#include "generalRule.h"
#include <string>

class createShape:public generalRule {
private:
    std::string param;
    bool terminal = false;
public:

    const std::string &getParam() const;

    void setParam(const std::string &param);

    bool isTerminal() const;

    void setTerminal(bool terminal);

    createShape(const std::string &param, bool terminal);

    void apply() override;

};


#endif //CGA_SHAPE_CREATESHAPE_H
