#ifndef ERROR_REG_H
#define ERROR_REG_H

#include "error_type.h"
#include <stdint.h>
#include <threads.h>

register uint32_t error __asm__ ("r12");

#endif // !ERROR_REG_H
