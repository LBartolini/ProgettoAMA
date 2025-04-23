#include "RewardVariablesAgatensiBartoliniPVModel.h"

RewardVariablesAgatensiBartoliniPVModel::RewardVariablesAgatensiBartoliniPVModel(bool expandTimeArrays) {
  TheModel=new CriticalSystemAgatensiBartoliniSAN();
  DefineName("RewardVariablesAgatensiBartoliniPVModel");
  CreatePVList(2, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* RewardVariablesAgatensiBartoliniPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new RewardVariablesAgatensiBartoliniPV0(timeindex);
    break;
  case 1:
    return new RewardVariablesAgatensiBartoliniPV1(timeindex);
    break;
  }
  return NULL;
}
