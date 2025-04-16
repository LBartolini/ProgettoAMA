#ifndef CriticalSystemAgatensiBartoliniSAN_H_
#define CriticalSystemAgatensiBartoliniSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Double lambda;
extern Double mu;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               CriticalSystemAgatensiBartoliniSAN Submodel Definition                   
*********************************************************************/

class CriticalSystemAgatensiBartoliniSAN:public SANModel{
public:

class Sys_Fail_TActivity:public Activity {
public:

  Place* Sys_W;
  short* Sys_W_Mobius_Mark;
  Place* A_W;
  short* A_W_Mobius_Mark;
  Place* B_W;
  short* B_W_Mobius_Mark;
  Place* C_W;
  short* C_W_Mobius_Mark;
  Place* Sys_F;
  short* Sys_F_Mobius_Mark;
  Place* UnRel;
  short* UnRel_Mobius_Mark;

  double* TheDistributionParameters;
  Sys_Fail_TActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
 bool Sys_FailureIP();
}; // Sys_Fail_TActivityActivity

class Sys_Restart_TActivity:public Activity {
public:

  Place* Sys_F;
  short* Sys_F_Mobius_Mark;
  Place* A_W;
  short* A_W_Mobius_Mark;
  Place* B_W;
  short* B_W_Mobius_Mark;
  Place* C_W;
  short* C_W_Mobius_Mark;
  Place* Sys_W;
  short* Sys_W_Mobius_Mark;

  double* TheDistributionParameters;
  Sys_Restart_TActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
 bool Sys_RestartIP();
}; // Sys_Restart_TActivityActivity

class A_Fail_TActivity:public Activity {
public:

  Place* A_W;
  short* A_W_Mobius_Mark;
  Place* A_F;
  short* A_F_Mobius_Mark;

  double* TheDistributionParameters;
  A_Fail_TActivity();
  ~A_Fail_TActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // A_Fail_TActivityActivity

class B_Fail_TActivity:public Activity {
public:

  Place* B_W;
  short* B_W_Mobius_Mark;
  Place* B_F;
  short* B_F_Mobius_Mark;

  double* TheDistributionParameters;
  B_Fail_TActivity();
  ~B_Fail_TActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // B_Fail_TActivityActivity

class C_Fail_TActivity:public Activity {
public:

  Place* C_W;
  short* C_W_Mobius_Mark;
  Place* C_F;
  short* C_F_Mobius_Mark;

  double* TheDistributionParameters;
  C_Fail_TActivity();
  ~C_Fail_TActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // C_Fail_TActivityActivity

class A_Repair_TActivity:public Activity {
public:

  Place* A_F;
  short* A_F_Mobius_Mark;
  Place* Sys_F;
  short* Sys_F_Mobius_Mark;
  Place* A_W;
  short* A_W_Mobius_Mark;

  double* TheDistributionParameters;
  A_Repair_TActivity();
  ~A_Repair_TActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
 bool A_Enabling_RepairIP();
}; // A_Repair_TActivityActivity

class B_Repair_TActivity:public Activity {
public:

  Place* A_F;
  short* A_F_Mobius_Mark;
  Place* B_F;
  short* B_F_Mobius_Mark;
  Place* Sys_F;
  short* Sys_F_Mobius_Mark;
  Place* B_W;
  short* B_W_Mobius_Mark;

  double* TheDistributionParameters;
  B_Repair_TActivity();
  ~B_Repair_TActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
 bool B_Enabling_RepairIP();
}; // B_Repair_TActivityActivity

class C_Repair_TActivity:public Activity {
public:

  Place* A_F;
  short* A_F_Mobius_Mark;
  Place* B_F;
  short* B_F_Mobius_Mark;
  Place* C_F;
  short* C_F_Mobius_Mark;
  Place* Sys_F;
  short* Sys_F_Mobius_Mark;
  Place* C_W;
  short* C_W_Mobius_Mark;

  double* TheDistributionParameters;
  C_Repair_TActivity();
  ~C_Repair_TActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
 bool C_Enabling_RepairIP();
}; // C_Repair_TActivityActivity

  //List of user-specified place names
  Place* A_W;
  Place* A_F;
  Place* B_W;
  Place* B_F;
  Place* C_W;
  Place* C_F;
  Place* Sys_W;
  Place* Sys_F;
  Place* UnRel;

  // Create instances of all actvities
  Sys_Fail_TActivity Sys_Fail_T;
  Sys_Restart_TActivity Sys_Restart_T;
  A_Fail_TActivity A_Fail_T;
  B_Fail_TActivity B_Fail_T;
  C_Fail_TActivity C_Fail_T;
  A_Repair_TActivity A_Repair_T;
  B_Repair_TActivity B_Repair_T;
  C_Repair_TActivity C_Repair_T;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup Sys_Fail_TGroup;
  PostselectGroup Sys_Restart_TGroup;

  CriticalSystemAgatensiBartoliniSAN();
  ~CriticalSystemAgatensiBartoliniSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end CriticalSystemAgatensiBartoliniSAN

#endif // CriticalSystemAgatensiBartoliniSAN_H_
