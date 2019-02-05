/**
 * @Author: S. Sharma <silentcat>
 * @Date:   2019-02-02T11:52:07-06:00
 * @Email:  silentcat@protonmail.com
 * @Last modified by:   silentcat
 * @Last modified time: 2019-02-04T20:38:03-06:00
 */

#include "liberrors.h"

/* Memory Allocation and Deallocation */

void *liberrors_smalloc(int size)
{
  if (size < 0) {
    liberrors_log_error("Invalid size: %d", size);
    return NULL;
  }

  void *ptr = malloc(size);
  if (!ptr) {
    liberrors_log_error("%s", strerror(errno));
    return NULL;
  }

  memset(ptr, 0x0, size);
  return ptr;
}

void *liberrors_scalloc(int size, int each)
{
  if (size < 0)
    liberrors_handle_exception(NULL, "Invalid size: %d", size);
  void *ptr = calloc(size, each);
  liberrors_assert(ptr, NULL);
  memset(ptr, 0x0, size * each);
  return ptr;
}

void *liberrors_srealloc(void *ptr, int size, int new_size)
{
  if (size < 0 || new_size < 0)
    liberrors_handle_exception(NULL, "Invalid size: %d or %d", size, new_size);
  if (new_size < size)
    memset(ptr + new_size, 0, size-new_size);
  ptr = realloc(ptr, new_size);
  liberrors_assert(ptr, NULL);
  return ptr;
}
