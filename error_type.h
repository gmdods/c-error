#ifndef ERROR_TYPE_H
#define ERROR_TYPE_H

#include <stdint.h>

enum errors {
	E_NONE,
	E_ALLOC,
	E_NIL,
	E_BAD,
	E_OVERFLOW,
};

typedef uint32_t error_t;

#endif // !ERROR_TYPE_H
