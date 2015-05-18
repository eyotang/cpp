all:backtrace

CPP_HEADER=-I.

backtrace:main.cc backtrace.cc
	gcc -o main.o -rdynamic -g -c main.cc ${CPP_HEADER}
	gcc -o backtrace.o -rdynamic -g -c backtrace.cc ${CPP_HEADER}
	gcc main.o backtrace.o -rdynamic -g -o backtrace

clean:
	rm -rf backtrace
	rm -rf *.o *.a *.la
