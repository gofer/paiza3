CXX      = g++
CXXFLAGS = -std=c++1y -O3 -I.
LD       = $(CXX)
LDFLAGS  = -L. -lstdc++

SRCS    = paiza3.cc
OBJS    = $(subst .cc,.o,$(SRCS))
TARGET  = paiza.exe

$(TARGET): $(OBJS)
	$(LD) -o $@ $(OBJS) $(LDFLAGS)

.SUFFIXES:	.cc .cpp
.cc.o:
	$(CXX) $(CXXFLAGS) -c $<
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: check
check: $(TARGET)
	./check

.PHONY: clean
clean:
	rm -f *.o
	rm -f output*.txt

.PHONY: distclean
distclean:
	make clean
	rm -f $(TARGET)
