
.PHONY: all clean

ifdef ROOTSYS
CXX := g++ -c 
LINKER := g++
CFLAGS = -g -Wall # -fPIC -DPIC # compiler options
SLIBFLAGS = -shared -Wl 
IFLAGS += -I $(ROOTSYS)/include/
ROOTLIBS = $(shell $(ROOTSYS)/bin/root-config --glibs) -lMinuit -lHtml
ROOTLIBS := $(filter-out -lNew,$(ROOTLIBS))
ROOTLIBS := $(filter-out -lpthread,$(ROOTLIBS))
else
all:
	@echo "ROOT not found!"
endif

all: goAnalysis

goAnalysis: *.o
	$(LINKER) $^ $(IFLAGS) $(ROOTLIBS) -o $@

%.o: %.C
	$(CXX) $(CFLAGS) $(IFLAGS) $(ROOTLIBS) $^ -o $@

clean:
	rm -rf *.o *.so *.d *.gch
