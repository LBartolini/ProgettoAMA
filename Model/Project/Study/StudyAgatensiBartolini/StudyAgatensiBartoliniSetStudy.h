
#ifndef StudyAgatensiBartoliniSetSTUDY_H_
#define StudyAgatensiBartoliniSetSTUDY_H_

#include "Reward/RewardVariablesAgatensiBartolini/RewardVariablesAgatensiBartoliniPVNodes.h"
#include "Reward/RewardVariablesAgatensiBartolini/RewardVariablesAgatensiBartoliniPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Double lambda;
extern Double mu;

class StudyAgatensiBartoliniSetStudy : public BaseStudyClass {
public:

StudyAgatensiBartoliniSetStudy();
~StudyAgatensiBartoliniSetStudy();

private:

double *lambdaValues;
double *muValues;

void SetValues_lambda();
void SetValues_mu();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

