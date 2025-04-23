
#include "Study/StudyAgatensiBartolini/StudyAgatensiBartoliniSetStudy.h"

//******************************************************
//Global Variables
//******************************************************
Double lambda;
Double mu;

//********************************************************
//StudyAgatensiBartoliniSetStudy Constructor
//********************************************************
StudyAgatensiBartoliniSetStudy::StudyAgatensiBartoliniSetStudy() {

  // define arrays of global variable names and types
  NumGVs = 2;
  NumExps = 9;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("lambda");
  GVTypes[0]=strdup("double");
  GVNames[1]=strdup("mu");
  GVTypes[1]=strdup("double");

  // create the arrays to store the values of each gv
  lambdaValues = new double[NumExps];
  muValues = new double[NumExps];

  // call methods to assign values to each gv
  SetValues_lambda();
  SetValues_mu();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//StudyAgatensiBartoliniSetStudy Destructor
//******************************************************
StudyAgatensiBartoliniSetStudy::~StudyAgatensiBartoliniSetStudy() {
  delete [] lambdaValues;
  delete [] muValues;
  delete ThePVModel;
}


//******************************************************
// set values for lambda
//******************************************************
void StudyAgatensiBartoliniSetStudy::SetValues_lambda() {
  lambdaValues[0] = 0.01;
  lambdaValues[1] = 0.01;
  lambdaValues[2] = 0.01;
  lambdaValues[3] = 0.001;
  lambdaValues[4] = 0.001;
  lambdaValues[5] = 0.001;
  lambdaValues[6] = 1.0E-4;
  lambdaValues[7] = 1.0E-4;
  lambdaValues[8] = 1.0E-4;
}


//******************************************************
// set values for mu
//******************************************************
void StudyAgatensiBartoliniSetStudy::SetValues_mu() {
  muValues[0] = 0.01;
  muValues[1] = 0.001;
  muValues[2] = 1.0E-4;
  muValues[3] = 0.01;
  muValues[4] = 0.001;
  muValues[5] = 1.0E-4;
  muValues[6] = 0.01;
  muValues[7] = 0.001;
  muValues[8] = 1.0E-4;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void StudyAgatensiBartoliniSetStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "lambda\tdouble\t" << lambda << endl;
  cout << "mu\tdouble\t" << mu << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *StudyAgatensiBartoliniSetStudy::GetGVValue(char *TheGVName) {
  if (strcmp("lambda", TheGVName) == 0)
    return &lambda;
  else if (strcmp("mu", TheGVName) == 0)
    return &mu;
  else 
    cerr<<"!! StudyAgatensiBartoliniSetStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void StudyAgatensiBartoliniSetStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("lambda", TheGVName) == 0)
    SetGvValue(lambda, *(double *)TheGVValue);
  else if (strcmp("mu", TheGVName) == 0)
    SetGvValue(mu, *(double *)TheGVValue);
  else 
    cerr<<"!! StudyAgatensiBartoliniSetStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void StudyAgatensiBartoliniSetStudy::SetGVs(int expNum) {
  SetGvValue(lambda, lambdaValues[expNum]);
  SetGvValue(mu, muValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new StudyAgatensiBartoliniSetStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* StudyAgatensiBartoliniSetStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new RewardVariablesAgatensiBartoliniPVModel(expandTimeArrays);
  return ThePVModel;
}


