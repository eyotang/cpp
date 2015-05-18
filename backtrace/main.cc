//#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#include <backtrace.h>

void fun1();
void fun2();
void fun3();


int main(void)
{
  int result = atexit(print_stacktrace);
  if (result != 0) {
    fprintf(stderr, "cannot set exit function\n");
    exit(EXIT_FAILURE);
  }

  fun3();

  return 0;
}

void fun1()
{
  fprintf(stderr, "Test exit callback!\n\n");
  exit(EXIT_SUCCESS);
}

void fun2()
{
  fun1();
}

void fun3()
{
  fun2();
}
