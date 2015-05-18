//#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"

#include "backtrace.h"

void fun1();
void fun2();
int fun3();

TEST(Testprint_stacktrace, callstack)
{
  int result = atexit(print_stacktrace);
  if (result != 0) {
    fprintf(stderr, "cannot set exit function\n");
    exit(EXIT_FAILURE);
  }

  ASSERT_EQ(0, fun3());
}

/*
int main(int argc, char **argv)
{
  int result = atexit(print_stacktrace);
  if (result != 0) {
    fprintf(stderr, "cannot set exit function\n");
    exit(EXIT_FAILURE);
  }

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/

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
