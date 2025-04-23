OBJS=RewardVariablesAgatensiBartoliniPVNodes.o RewardVariablesAgatensiBartoliniPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libRewardVariablesAgatensiBartoliniPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libRewardVariablesAgatensiBartoliniPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libRewardVariablesAgatensiBartoliniPV.a: FORCE
	$(MAKE) lib TARGET=libRewardVariablesAgatensiBartoliniPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libRewardVariablesAgatensiBartoliniPV_debug.a: FORCE
	$(MAKE) lib TARGET=libRewardVariablesAgatensiBartoliniPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

