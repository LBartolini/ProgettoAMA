OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lgenMain
MAINLIB_debug=-lgenMain_debug
SIMLIB=gen
SIMLIB_debug=gen_debug
SIMLIB_trace=gen_trace
PROJECTLIBS=-lStudyAgatensiBartoliniSetStudy -lRewardVariablesAgatensiBartoliniPV -lCriticalSystemAgatensiBartoliniSAN 
PROJECTLIBS_debug=-lStudyAgatensiBartoliniSetStudy_debug -lRewardVariablesAgatensiBartoliniPV_debug -lCriticalSystemAgatensiBartoliniSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
SSGAgatensiBartoliniGen_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=SSGAgatensiBartoliniGen_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
SSGAgatensiBartoliniGen_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=SSGAgatensiBartoliniGen_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
SSGAgatensiBartoliniGen_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=SSGAgatensiBartoliniGen_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/CriticalSystemAgatensiBartolini/ && $(MAKE) clean
	cd ../../Reward/RewardVariablesAgatensiBartolini/ && $(MAKE) clean
	cd ../../Study/StudyAgatensiBartolini/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[CriticalSystemAgatensiBartolini]"
	cd ../../Atomic/CriticalSystemAgatensiBartolini/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[RewardVariablesAgatensiBartolini]"
	cd ../../Reward/RewardVariablesAgatensiBartolini/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[StudyAgatensiBartolini]"
	cd ../../Study/StudyAgatensiBartolini/ && $(MAKE) $(@F)


