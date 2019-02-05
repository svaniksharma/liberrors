/**
 * @Author: S. Sharma <silentcat>
 * @Date:   2019-02-02T11:52:07-06:00
 * @Email:  silentcat@protonmail.com
 * @Last modified by:   silentcat
 * @Last modified time: 2019-02-04T20:48:55-06:00
 */

#ifndef C_ALGO_LIBERRORS_H
#define C_ALGO_LIBERRORS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

/* Macros for Logging Errors */

#define liberrors_log_msg(msg, type, ...) { \
  fprintf(stderr, "[%s:%d]" type ": " msg ".\n", __FILE__, __LINE__, ##__VA_ARGS__); \
}

#ifdef LIBERRORS_ALLOW_DEBUG

#define liberrors_log_debug(msg, ...) { \
  liberrors_log_msg(msg, "[DEBUG]", ##__VA_ARGS__); \
}

#else

#define liberrors_log_debug(msg, ...) { }

#endif

#define liberrors_log_error(msg, ...) { \
  liberrors_log_msg(msg, "[ERROR]", ##__VA_ARGS__); \
}

#define liberrors_log_info(msg, ...) { \
  liberrors_log_msg(msg, "[INFO]", ##__VA_ARGS__); \
}

/* Macros for NULL Checks. */

#define liberrors_assert(obj, ...) { \
  if (!obj) { \
    liberrors_log_error("obj == NULL"); \
    return __VA_ARGS__; \
  } \
}

#define liberrors_handle_exception(ret, msg, ...) { \
  liberrors_log_error(msg, ##__VA_ARGS__) \
  return ret; \
}

/* Functions for Safely Allocating Memory */

void *liberrors_smalloc(int size);
void *liberrors_scalloc(int size, int each);
void *liberrors_srealloc(void *ptr, int size, int new_size);

#endif
