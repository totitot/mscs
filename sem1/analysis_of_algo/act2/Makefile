
CXX=g++
CFLAGS=-std=c++11
LDFLAGS=
OBJEXT=o
OBJS=node.$(OBJEXT) statv3.$(OBJEXT)
MAIN=main.cpp
TARGET=test

.PHONY: all
all: comp link run 

.PHONY: link
link: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) $(OBJS) $(MAIN) -o $@

.PHONY: comp
comp: $(OBJS)

%.$(OBJEXT): %.cc %.h
	$(CXX) $(CFLAGS) $(LDFLAGS) -c $< -o $@

%.$(OBJEXT): %.cpp %.h
	$(CXX) $(CFLAGS) $(LDFLAGS) -c $< -o $@

.PHONY: again
again: clean all

.PHONY: run
run: $(TARGET)
	-@./$<

.PHONY: clean
clean:
	-@rm -rf *.$(OBJEXT) $(TARGET) *.exe


