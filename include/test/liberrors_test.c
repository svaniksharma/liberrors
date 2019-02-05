/**
 * @Author: S. Sharma <silentcat>
 * @Date:   2019-02-02T11:52:07-06:00
 * @Email:  silentcat@protonmail.com
 * @Last modified by:   silentcat
 * @Last modified time: 2019-02-04T20:51:41-06:00
 */


#include "../liberrors.h"

int test_func(const char *val)
{
  liberrors_assert(val, -1);
  return 0;
}

int main(int argc, char *argv[])
{
  const int val = 1, val2 = 2, val3 = 3;
  liberrors_log_info("Test: %d", val);
  liberrors_log_error("Test: %d", val2);
  liberrors_log_debug("Test: %d", val3);

  char *test = NULL;
  liberrors_log_debug("Function test_func reported: %d", test_func(test));
  test = liberrors_smalloc(123);
  liberrors_assert(test, -1);
  memset(test, 'A', 120);
  memset(test + 120, 'B', 2);
  liberrors_log_debug("Function test_func reported: %d", test_func(test));
  liberrors_log_debug("Value of test is %s", test);
  test = liberrors_srealloc(test, 123, 130);
  memset(test + 122, 'C', 6);
  liberrors_log_debug("Value of test is %s", test);
  char *test2 = NULL;
  free(test);
  return 0;
}
