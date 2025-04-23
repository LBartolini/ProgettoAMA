#ifndef _REWARDVARIABLESAGATENSIBARTOLINI_PVMODEL_
#define _REWARDVARIABLESAGATENSIBARTOLINI_PVMODEL_
#include "RewardVariablesAgatensiBartoliniPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/CriticalSystemAgatensiBartolini/CriticalSystemAgatensiBartoliniSAN.h"
class RewardVariablesAgatensiBartoliniPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  RewardVariablesAgatensiBartoliniPVModel(bool expandtimepoints);
};

#endif
