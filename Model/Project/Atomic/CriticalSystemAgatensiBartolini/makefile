OBJS=CriticalSystemAgatensiBartoliniSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libCriticalSystemAgatensiBartoliniSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libCriticalSystemAgatensiBartoliniSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libCriticalSystemAgatensiBartoliniSAN.a: FORCE
	$(MAKE) lib TARGET=libCriticalSystemAgatensiBartoliniSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libCriticalSystemAgatensiBartoliniSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libCriticalSystemAgatensiBartoliniSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

