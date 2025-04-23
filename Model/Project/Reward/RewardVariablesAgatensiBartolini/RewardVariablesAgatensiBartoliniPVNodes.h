#ifndef _REWARDVARIABLESAGATENSIBARTOLINI_PVS_
#define _REWARDVARIABLESAGATENSIBARTOLINI_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/CriticalSystemAgatensiBartolini/CriticalSystemAgatensiBartoliniSAN.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class RewardVariablesAgatensiBartoliniPV0Worker:public InstantOfTime
{
 public:
  CriticalSystemAgatensiBartoliniSAN *CriticalSystemAgatensiBartolini;
  
  RewardVariablesAgatensiBartoliniPV0Worker();
  ~RewardVariablesAgatensiBartoliniPV0Worker();
  double Reward_Function();
};

class RewardVariablesAgatensiBartoliniPV0:public PerformanceVariableNode
{
 public:
  CriticalSystemAgatensiBartoliniSAN *TheCriticalSystemAgatensiBartoliniSAN;

  RewardVariablesAgatensiBartoliniPV0Worker *RewardVariablesAgatensiBartoliniPV0WorkerList;

  RewardVariablesAgatensiBartoliniPV0(int timeindex=0);
  ~RewardVariablesAgatensiBartoliniPV0();
  void CreateWorkerList(void);
};

class RewardVariablesAgatensiBartoliniPV1Worker:public SteadyState
{
 public:
  CriticalSystemAgatensiBartoliniSAN *CriticalSystemAgatensiBartolini;
  
  RewardVariablesAgatensiBartoliniPV1Worker();
  ~RewardVariablesAgatensiBartoliniPV1Worker();
  double Reward_Function();
};

class RewardVariablesAgatensiBartoliniPV1:public PerformanceVariableNode
{
 public:
  CriticalSystemAgatensiBartoliniSAN *TheCriticalSystemAgatensiBartoliniSAN;

  RewardVariablesAgatensiBartoliniPV1Worker *RewardVariablesAgatensiBartoliniPV1WorkerList;

  RewardVariablesAgatensiBartoliniPV1(int timeindex=0);
  ~RewardVariablesAgatensiBartoliniPV1();
  void CreateWorkerList(void);
};

#endif
