#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#include <backtrace.h>

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
