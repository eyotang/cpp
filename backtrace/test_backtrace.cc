#include <stdio.h>
#include <stdlib.h>

#ifdef UNIT_TEST
#include "gtest/gtest.h"
#endif /* UNIT_TEST */

#include "backtrace.h"

void fun1();
void fun2();
int fun3();

#ifdef UNIT_TEST
TEST(Testprint_stacktrace, callstack)
{
  int result = atexit(print_stacktrace);
  if (result != 0) {
    fprintf(stderr, "cannot set exit function\n");
    exit(EXIT_FAILURE);
  }

  ASSERT_EQ(0, fun3());
}
#else
int main(int argc, char **argv)
{
  int result = atexit(print_stacktrace);
  if (result != 0) {
    fprintf(stderr, "cannot set exit function\n");
    exit(EXIT_FAILURE);
  }

  return fun3();
}
#endif

void fun1()
{
  fprintf(stderr, "Test exit callback!\n\n");
  exit(EXIT_SUCCESS);
}

void fun2()
{
  fun1();
}

int fun3()
{
  fun2();
  return 0;
}
