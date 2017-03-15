//
// Created by mashenjun on 13-3-17.
//
#include <iostream>
#include "generalRule.h"

//void apply(){
//    std::cout<< "call appy method " <<std::endl;
//};
const std::string &generalRule::getOperationType() const {
    return operationType;
}

void generalRule::setOperationType(const std::string &operationType) {
    generalRule::operationType = operationType;
}

generalRule::generalRule(const std::string &operationType) : operationType(operationType) {}
