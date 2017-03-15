//
// Created by mashenjun on 13-3-17.
//

#include "workflow.h"
#include <iostream>
#include "../util/createShape.h"
#include "../util/scopeRule.h"
#include "../util/basicSplitRule.h"
#include "../util/nestedBasicSplitRule.h"
#include "../util/componentSplitRule.h"
#include "../util/repeatRule.h"


//void workflow::setProb(float prob) {
//    workflow::prob = prob;
//}

void workflow::process(){
    for (int i = 0; i < this->steps.size(); ++i)
    {
        std::cout<< "<" <<steps[i]->getOperationType()<< ">";
        steps[i]->apply();
//        if (steps[i]->getOperationType() == "basic_split"){
////            basicSplitRule * operation = dynamic_cast<basicSplitRule*>(&i);
//            basicSplitRule& operation = static_cast<basicSplitRule&>(steps[i]);
//            operation.apply();
//        }
//        else if (steps[i]->getOperationType() == "component_split") {
////            componentSplitRule * operation = dynamic_cast<componentSplitRule*>(&i);
//            componentSplitRule& operation = static_cast<componentSplitRule&>(steps[i]);
//            operation.apply();
//        }
//        else if (steps[i]->getOperationType() == "create_shape") {
////            createShape * operation = dynamic_cast<createShape*>(&i);
//            createShape& operation = static_cast<createShape&>(steps[i]);
//            operation.apply();
//        }
//        else if (steps[i]->getOperationType() == "nested_basic_split") {
////            nestedBasicSplitRule * operation = dynamic_cast<nestedBasicSplitRule*>(&i);
//            nestedBasicSplitRule& operation = static_cast<nestedBasicSplitRule&>(steps[i]);
//            operation.apply();
//        }
//        else if (steps[i]->getOperationType() == "repeat") {
////            repeatRule * operation = dynamic_cast<repeatRule*>(&i);
//            repeatRule& operation = static_cast<repeatRule&>(steps[i]);
//            operation.apply();
//        }
//        else if (steps[i]->getOperationType() == "scope") {
////            scopeRule * operation = dynamic_cast<scopeRule*>(&i);
//            scopeRule& operation = static_cast<scopeRule&>(steps[i]);
//            operation.apply();
//        }
    }
    return ;
}

workflow::workflow(float prob, const std::vector<std::shared_ptr<generalRule>> &steps) : prob(prob), steps(steps) {}


