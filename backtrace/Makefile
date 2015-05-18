all:test_backtrace

CXX = g++
CXX_FLAGS = -rdynamic -g
LIBS = -lgtest_main -lgtest -lpthread
INCS=-I./

OBJS = test_backtrace.o backtrace.o

test_backtrace:$(OBJS)
	$(CXX) $(CXX_FLAGS) $(LIBS) -o test_backtrace $(OBJS)

.cc.o:
	$(CXX) $(CXX_FLAGS) -c $< -o $@ $(INCS)

clean:
	rm -rf test_backtrace
	rm -rf *.o *.a *.la
