#ifndef ERROR_LOCAL_H
#define ERROR_LOCAL_H

#include "error_type.h"
#include <threads.h>

static thread_local error_t error = 0;

#endif // !ERROR_LOCAL_H
