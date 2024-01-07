#include "error_reg.h"
#include "error_type.h"
#include <assert.h>
#include <stdlib.h>

struct block {
	void * ptr;
	size_t bytes;
};

struct block alloc(size_t bytes) {
	if (bytes == 0) return (error = E_BAD, (struct block){0});
	void * ptr = calloc(bytes, 1);
	if (!ptr) return (error = E_ALLOC, (struct block){0});
	return (struct block){.ptr = ptr, .bytes = bytes};
}

void dealloc(struct block * block) {
	if (!block) error = E_BAD;
	if (!block->ptr) error = E_NIL;
	free(block->ptr);
	*block = (struct block){0};
}

void test(void) {
	alloc(0), assert(error == E_BAD);
	dealloc(NULL), assert(error == E_BAD);
	dealloc(&(struct block){0}), assert(error == E_NIL);
}
