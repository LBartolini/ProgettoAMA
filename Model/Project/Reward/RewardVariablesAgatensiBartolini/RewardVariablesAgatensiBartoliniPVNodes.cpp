#include "RewardVariablesAgatensiBartoliniPVNodes.h"

RewardVariablesAgatensiBartoliniPV0Worker::RewardVariablesAgatensiBartoliniPV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&CriticalSystemAgatensiBartolini);
}

RewardVariablesAgatensiBartoliniPV0Worker::~RewardVariablesAgatensiBartoliniPV0Worker() {
  delete [] TheModelPtr;
}

double RewardVariablesAgatensiBartoliniPV0Worker::Reward_Function(void) {

return (1 - CriticalSystemAgatensiBartolini->UnRel->Mark());

return (0);



}

RewardVariablesAgatensiBartoliniPV0::RewardVariablesAgatensiBartoliniPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheCriticalSystemAgatensiBartoliniSAN);
  double startpts[6]={24, 360, 1080, 2520, 5400, 11160};
  double stoppts[6]={24, 360, 1080, 2520, 5400, 11160};
  Initialize("Reliability",(RewardType)0,6, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("UnRel","CriticalSystemAgatensiBartolini");
}

RewardVariablesAgatensiBartoliniPV0::~RewardVariablesAgatensiBartoliniPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardVariablesAgatensiBartoliniPV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardVariablesAgatensiBartoliniPV0Worker;
}
RewardVariablesAgatensiBartoliniPV1Worker::RewardVariablesAgatensiBartoliniPV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&CriticalSystemAgatensiBartolini);
}

RewardVariablesAgatensiBartoliniPV1Worker::~RewardVariablesAgatensiBartoliniPV1Worker() {
  delete [] TheModelPtr;
}

double RewardVariablesAgatensiBartoliniPV1Worker::Reward_Function(void) {

return CriticalSystemAgatensiBartolini->Sys_W->Mark();

return (0);



}

RewardVariablesAgatensiBartoliniPV1::RewardVariablesAgatensiBartoliniPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheCriticalSystemAgatensiBartoliniSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("Availability",(RewardType)3,1, startpts, stoppts, timeindex, 0,1, 1);
  Type = steady_state;
  AddVariableDependency("Sys_W","CriticalSystemAgatensiBartolini");
}

RewardVariablesAgatensiBartoliniPV1::~RewardVariablesAgatensiBartoliniPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RewardVariablesAgatensiBartoliniPV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RewardVariablesAgatensiBartoliniPV1Worker;
}
