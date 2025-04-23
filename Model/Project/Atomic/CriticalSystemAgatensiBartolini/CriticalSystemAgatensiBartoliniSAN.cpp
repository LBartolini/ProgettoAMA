

// This C++ file was created by SanEditor

#include "Atomic/CriticalSystemAgatensiBartolini/CriticalSystemAgatensiBartoliniSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         CriticalSystemAgatensiBartoliniSAN Constructor             
******************************************************************/


CriticalSystemAgatensiBartoliniSAN::CriticalSystemAgatensiBartoliniSAN(){


  Activity* InitialActionList[8]={
    &Sys_Fail_T, //0
    &Sys_Restart_T, //1
    &A_Fail_T, //2
    &B_Fail_T, //3
    &C_Fail_T, //4
    &A_Repair_T, //5
    &B_Repair_T, //6
    &C_Repair_T  // 7
  };

  BaseGroupClass* InitialGroupList[8]={
    (BaseGroupClass*) &(A_Fail_T), 
    (BaseGroupClass*) &(B_Fail_T), 
    (BaseGroupClass*) &(C_Fail_T), 
    (BaseGroupClass*) &(A_Repair_T), 
    (BaseGroupClass*) &(B_Repair_T), 
    (BaseGroupClass*) &(C_Repair_T), 
    (BaseGroupClass*) &(Sys_Fail_T), 
    (BaseGroupClass*) &(Sys_Restart_T)
  };

  A_W = new Place("A_W" ,1);
  A_F = new Place("A_F" ,0);
  B_W = new Place("B_W" ,2);
  B_F = new Place("B_F" ,0);
  C_W = new Place("C_W" ,3);
  C_F = new Place("C_F" ,0);
  Sys_W = new Place("Sys_W" ,1);
  Sys_F = new Place("Sys_F" ,0);
  UnRel = new Place("UnRel" ,0);
  BaseStateVariableClass* InitialPlaces[9]={
    A_W,  // 0
    A_F,  // 1
    B_W,  // 2
    B_F,  // 3
    C_W,  // 4
    C_F,  // 5
    Sys_W,  // 6
    Sys_F,  // 7
    UnRel   // 8
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("CriticalSystemAgatensiBartolini", 9, InitialPlaces, 
                        0, InitialROPlaces, 
                        8, InitialActionList, 8, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[17][2]={ 
    {6,0}, {7,0}, {8,0}, {7,1}, {6,1}, {0,2}, {1,2}, {2,3}, {3,3}, 
    {4,4}, {5,4}, {1,5}, {0,5}, {3,6}, {2,6}, {5,7}, {4,7}
  };
  for(int n=0;n<17;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[20][2]={ 
    {6,0}, {0,0}, {2,0}, {4,0}, {7,1}, {0,1}, {2,1}, {4,1}, {0,2}, 
    {2,3}, {4,4}, {1,5}, {7,5}, {3,6}, {1,6}, {7,6}, {5,7}, {1,7}, 
    {3,7}, {7,7}
  };
  for(int n=0;n<20;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<8;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void CriticalSystemAgatensiBartoliniSAN::CustomInitialization() {

}
CriticalSystemAgatensiBartoliniSAN::~CriticalSystemAgatensiBartoliniSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void CriticalSystemAgatensiBartoliniSAN::assignPlacesToActivitiesInst(){
  Sys_Fail_T.Sys_W = (Place*) LocalStateVariables[6];
  Sys_Fail_T.A_W = (Place*) LocalStateVariables[0];
  Sys_Fail_T.B_W = (Place*) LocalStateVariables[2];
  Sys_Fail_T.C_W = (Place*) LocalStateVariables[4];
  Sys_Fail_T.Sys_F = (Place*) LocalStateVariables[7];
  Sys_Fail_T.UnRel = (Place*) LocalStateVariables[8];
  Sys_Restart_T.Sys_F = (Place*) LocalStateVariables[7];
  Sys_Restart_T.A_W = (Place*) LocalStateVariables[0];
  Sys_Restart_T.B_W = (Place*) LocalStateVariables[2];
  Sys_Restart_T.C_W = (Place*) LocalStateVariables[4];
  Sys_Restart_T.Sys_W = (Place*) LocalStateVariables[6];
}
void CriticalSystemAgatensiBartoliniSAN::assignPlacesToActivitiesTimed(){
  A_Fail_T.A_W = (Place*) LocalStateVariables[0];
  A_Fail_T.A_F = (Place*) LocalStateVariables[1];
  B_Fail_T.B_W = (Place*) LocalStateVariables[2];
  B_Fail_T.B_F = (Place*) LocalStateVariables[3];
  C_Fail_T.C_W = (Place*) LocalStateVariables[4];
  C_Fail_T.C_F = (Place*) LocalStateVariables[5];
  A_Repair_T.A_F = (Place*) LocalStateVariables[1];
  A_Repair_T.Sys_F = (Place*) LocalStateVariables[7];
  A_Repair_T.A_W = (Place*) LocalStateVariables[0];
  B_Repair_T.B_F = (Place*) LocalStateVariables[3];
  B_Repair_T.A_F = (Place*) LocalStateVariables[1];
  B_Repair_T.Sys_F = (Place*) LocalStateVariables[7];
  B_Repair_T.B_W = (Place*) LocalStateVariables[2];
  C_Repair_T.C_F = (Place*) LocalStateVariables[5];
  C_Repair_T.A_F = (Place*) LocalStateVariables[1];
  C_Repair_T.B_F = (Place*) LocalStateVariables[3];
  C_Repair_T.Sys_F = (Place*) LocalStateVariables[7];
  C_Repair_T.C_W = (Place*) LocalStateVariables[4];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================Sys_Fail_TActivity========================*/


CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::Sys_Fail_TActivity(){
  ActivityInitialize("Sys_Fail_T",6,Instantaneous , RaceEnabled, 3,4, false);
}

void CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::LinkVariables(){
  Sys_W->Register(&Sys_W_Mobius_Mark);
  A_W->Register(&A_W_Mobius_Mark);
  B_W->Register(&B_W_Mobius_Mark);
  C_W->Register(&C_W_Mobius_Mark);
  Sys_F->Register(&Sys_F_Mobius_Mark);
  UnRel->Register(&UnRel_Mobius_Mark);
}

bool CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Sys_W_Mobius_Mark)) >=1)&&(Sys_FailureIP()));
  return NewEnabled;
}

    bool CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::Sys_FailureIP(){
bool a, b, c, d;
a = (A_W -> Mark() == 0);
b = (B_W -> Mark() == 0);
c = (C_W -> Mark() == 0);
return (a || (b && c));
return 0;
    }

double CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::Weight(){ 
  return 1;
}

bool CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::ReactivationPredicate(){ 
  return false;
}

bool CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::ReactivationFunction(){ 
  return false;
}

double CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::SampleDistribution(){
  return 0;
}

double* CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::ReturnDistributionParameters(){
    return NULL;
}

int CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::Rank(){
  return 1;
}

BaseActionClass* CriticalSystemAgatensiBartoliniSAN::Sys_Fail_TActivity::Fire(){
  ;
  (*(Sys_W_Mobius_Mark))--;
  UnRel -> Mark() = 1;
  (*(Sys_F_Mobius_Mark))++;
  return this;
}

/*======================Sys_Restart_TActivity========================*/


CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::Sys_Restart_TActivity(){
  ActivityInitialize("Sys_Restart_T",7,Instantaneous , RaceEnabled, 2,4, false);
}

void CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::LinkVariables(){
  Sys_F->Register(&Sys_F_Mobius_Mark);
  A_W->Register(&A_W_Mobius_Mark);
  B_W->Register(&B_W_Mobius_Mark);
  C_W->Register(&C_W_Mobius_Mark);
  Sys_W->Register(&Sys_W_Mobius_Mark);
}

bool CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Sys_F_Mobius_Mark)) >=1)&&(Sys_RestartIP()));
  return NewEnabled;
}

    bool CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::Sys_RestartIP(){
bool a, b, c, d;
a = (A_W -> Mark() == 1);
b = (B_W -> Mark() > 0);
c = (C_W -> Mark() > 0);
return (a && (b || c));
return 0;
    }

double CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::Weight(){ 
  return 1;
}

bool CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::ReactivationPredicate(){ 
  return false;
}

bool CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::ReactivationFunction(){ 
  return false;
}

double CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::SampleDistribution(){
  return 0;
}

double* CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::ReturnDistributionParameters(){
    return NULL;
}

int CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::Rank(){
  return 1;
}

BaseActionClass* CriticalSystemAgatensiBartoliniSAN::Sys_Restart_TActivity::Fire(){
  ;
  (*(Sys_F_Mobius_Mark))--;
  (*(Sys_W_Mobius_Mark))++;
  return this;
}

/*======================A_Fail_TActivity========================*/

CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::A_Fail_TActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("A_Fail_T",0,Exponential, RaceEnabled, 2,1, false);
}

CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::~A_Fail_TActivity(){
  delete[] TheDistributionParameters;
}

void CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::LinkVariables(){
  A_W->Register(&A_W_Mobius_Mark);
  A_F->Register(&A_F_Mobius_Mark);
}

bool CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(A_W_Mobius_Mark)) >=1));
  return NewEnabled;
}

double CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::Rate(){
  return lambda / 4;
  return 1.0;  // default rate if none is specified
}

double CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::Weight(){ 
  return 1;
}

bool CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::ReactivationPredicate(){ 
  return false;
}

bool CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::ReactivationFunction(){ 
  return false;
}

double CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::SampleDistribution(){
  return TheDistribution->Exponential(lambda / 4);
}

double* CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::Rank(){
  return 1;
}

BaseActionClass* CriticalSystemAgatensiBartoliniSAN::A_Fail_TActivity::Fire(){
  (*(A_W_Mobius_Mark))--;
  (*(A_F_Mobius_Mark))++;
  return this;
}

/*======================B_Fail_TActivity========================*/

CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::B_Fail_TActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("B_Fail_T",1,Exponential, RaceEnabled, 2,1, false);
}

CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::~B_Fail_TActivity(){
  delete[] TheDistributionParameters;
}

void CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::LinkVariables(){
  B_W->Register(&B_W_Mobius_Mark);
  B_F->Register(&B_F_Mobius_Mark);
}

bool CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(B_W_Mobius_Mark)) >=1));
  return NewEnabled;
}

double CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::Rate(){
  return B_W -> Mark() * lambda / 2;
  return 1.0;  // default rate if none is specified
}

double CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::Weight(){ 
  return 1;
}

bool CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::ReactivationPredicate(){ 
  return false;
}

bool CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::ReactivationFunction(){ 
  return false;
}

double CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::SampleDistribution(){
  return TheDistribution->Exponential(B_W -> Mark() * lambda / 2);
}

double* CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::Rank(){
  return 1;
}

BaseActionClass* CriticalSystemAgatensiBartoliniSAN::B_Fail_TActivity::Fire(){
  (*(B_W_Mobius_Mark))--;
  (*(B_F_Mobius_Mark))++;
  return this;
}

/*======================C_Fail_TActivity========================*/

CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::C_Fail_TActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("C_Fail_T",2,Exponential, RaceEnabled, 2,1, false);
}

CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::~C_Fail_TActivity(){
  delete[] TheDistributionParameters;
}

void CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::LinkVariables(){
  C_W->Register(&C_W_Mobius_Mark);
  C_F->Register(&C_F_Mobius_Mark);
}

bool CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(C_W_Mobius_Mark)) >=1));
  return NewEnabled;
}

double CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::Rate(){
  return C_W -> Mark() * lambda;
  return 1.0;  // default rate if none is specified
}

double CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::Weight(){ 
  return 1;
}

bool CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::ReactivationPredicate(){ 
  return false;
}

bool CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::ReactivationFunction(){ 
  return false;
}

double CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::SampleDistribution(){
  return TheDistribution->Exponential(C_W -> Mark() * lambda);
}

double* CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::Rank(){
  return 1;
}

BaseActionClass* CriticalSystemAgatensiBartoliniSAN::C_Fail_TActivity::Fire(){
  (*(C_W_Mobius_Mark))--;
  (*(C_F_Mobius_Mark))++;
  return this;
}

/*======================A_Repair_TActivity========================*/

CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::A_Repair_TActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("A_Repair_T",3,Exponential, RaceEnabled, 2,2, false);
}

CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::~A_Repair_TActivity(){
  delete[] TheDistributionParameters;
}

void CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::LinkVariables(){
  A_F->Register(&A_F_Mobius_Mark);
  Sys_F->Register(&Sys_F_Mobius_Mark);
  A_W->Register(&A_W_Mobius_Mark);
}

bool CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(A_F_Mobius_Mark)) >=1)&&(A_Enabling_RepairIP()));
  return NewEnabled;
}

    bool CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::A_Enabling_RepairIP(){
return (Sys_F -> Mark() == 1);
return 0;
    }

double CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::Rate(){
  return mu / 4;
  return 1.0;  // default rate if none is specified
}

double CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::Weight(){ 
  return 1;
}

bool CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::ReactivationPredicate(){ 
  return false;
}

bool CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::ReactivationFunction(){ 
  return false;
}

double CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::SampleDistribution(){
  return TheDistribution->Exponential(mu / 4);
}

double* CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::Rank(){
  return 1;
}

BaseActionClass* CriticalSystemAgatensiBartoliniSAN::A_Repair_TActivity::Fire(){
  ;
  (*(A_F_Mobius_Mark))--;
  (*(A_W_Mobius_Mark))++;
  return this;
}

/*======================B_Repair_TActivity========================*/

CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::B_Repair_TActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("B_Repair_T",4,Exponential, RaceEnabled, 2,3, false);
}

CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::~B_Repair_TActivity(){
  delete[] TheDistributionParameters;
}

void CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::LinkVariables(){
  B_F->Register(&B_F_Mobius_Mark);
  A_F->Register(&A_F_Mobius_Mark);
  Sys_F->Register(&Sys_F_Mobius_Mark);
  B_W->Register(&B_W_Mobius_Mark);
}

bool CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(B_F_Mobius_Mark)) >=1)&&(B_Enabling_RepairIP()));
  return NewEnabled;
}

    bool CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::B_Enabling_RepairIP(){
bool a, b;
a = (Sys_F -> Mark() == 1);
b = (A_F ->Mark() == 0);
return (a && b);
return 0;
    }

double CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::Rate(){
  return mu / 2;
  return 1.0;  // default rate if none is specified
}

double CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::Weight(){ 
  return 1;
}

bool CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::ReactivationPredicate(){ 
  return false;
}

bool CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::ReactivationFunction(){ 
  return false;
}

double CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::SampleDistribution(){
  return TheDistribution->Exponential(mu / 2);
}

double* CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::Rank(){
  return 1;
}

BaseActionClass* CriticalSystemAgatensiBartoliniSAN::B_Repair_TActivity::Fire(){
  ;
  (*(B_F_Mobius_Mark))--;
  (*(B_W_Mobius_Mark))++;
  return this;
}

/*======================C_Repair_TActivity========================*/

CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::C_Repair_TActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("C_Repair_T",5,Exponential, RaceEnabled, 2,4, false);
}

CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::~C_Repair_TActivity(){
  delete[] TheDistributionParameters;
}

void CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::LinkVariables(){
  C_F->Register(&C_F_Mobius_Mark);
  A_F->Register(&A_F_Mobius_Mark);
  B_F->Register(&B_F_Mobius_Mark);
  Sys_F->Register(&Sys_F_Mobius_Mark);
  C_W->Register(&C_W_Mobius_Mark);
}

bool CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(C_F_Mobius_Mark)) >=1)&&(C_Enabling_RepairIP()));
  return NewEnabled;
}

    bool CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::C_Enabling_RepairIP(){
bool a, b, c;
a = (Sys_F -> Mark() == 1);
b = (A_F ->Mark() == 0);
c = (B_F ->Mark() == 0);
return (a && b && c);
return 0;
    }

double CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::Rate(){
  return mu;
  return 1.0;  // default rate if none is specified
}

double CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::Weight(){ 
  return 1;
}

bool CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::ReactivationPredicate(){ 
  return false;
}

bool CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::ReactivationFunction(){ 
  return false;
}

double CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::SampleDistribution(){
  return TheDistribution->Exponential(mu);
}

double* CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::Rank(){
  return 1;
}

BaseActionClass* CriticalSystemAgatensiBartoliniSAN::C_Repair_TActivity::Fire(){
  ;
  (*(C_F_Mobius_Mark))--;
  (*(C_W_Mobius_Mark))++;
  return this;
}

