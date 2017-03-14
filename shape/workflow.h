//
// Created by mashenjun on 13-3-17.
//
#include <string>
#include <list>
#ifndef CGA_SHAPE_FUNCTION_H
#define CGA_SHAPE_FUNCTION_H

#include <map>
#include <memory>
#include <vector>
#include "../util/generalRule.h"

class workflow {
private:
    float prob=1;
    std::vector<std::shared_ptr<generalRule>> steps;
public:
    void process();

    workflow(float prob, const std::vector<std::shared_ptr<generalRule>> &steps);
};


#endif //CGA_SHAPE_FUNCTION_H
