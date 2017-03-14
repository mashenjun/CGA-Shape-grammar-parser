//
// Created by mashenjun on 13-3-17.
//

#include "workflow.h"


//void workflow::setProb(float prob) {
//    workflow::prob = prob;
//}

void workflow::process(){

    return ;
}

workflow::workflow(float prob, const std::vector<std::shared_ptr<generalRule>> &steps) : prob(prob), steps(steps) {}

