#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

void fun1();
void fun2();
void fun3();

void print_stacktrace(void);

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
  //print_stacktrace();
}

void fun2()
{
  fun1();
}

void fun3()
{
  fun2();
}

void print_stacktrace(void)
{
  int size = 16;
  void *array[size];
  int stack_num = backtrace(array, size);
  char **stacktrace = backtrace_symbols(array, stack_num);

  fprintf(stderr, "back trace, symbols:\n");
  for (int i = 0; i < stack_num; i++)
  {
    fprintf(stderr, "#%d %p in %s\n", i, array[i], stacktrace[i]);
  }

  free(stacktrace);
}
