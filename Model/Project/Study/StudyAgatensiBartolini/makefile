OBJS=StudyAgatensiBartoliniSetStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libStudyAgatensiBartoliniSetStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libStudyAgatensiBartoliniSetStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libStudyAgatensiBartoliniSetStudy.a: FORCE
	$(MAKE) lib TARGET=libStudyAgatensiBartoliniSetStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libStudyAgatensiBartoliniSetStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libStudyAgatensiBartoliniSetStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

