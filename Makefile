CC = gcc
CFLAGS = -Wall -Wpedantic -Wextra \
	 -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function \
	 -march=native -std=c11

asm: error_local.S error_reg.S
.PHONY: asm

error_local.S: error_local.c error_local.h error_type.h
	$(CC) $(CFLAGS) -O3 -S -masm=intel $< -o $@

error_reg.S: error_reg.c error_reg.h error_type.h
	$(CC) $(CFLAGS) -O3 -S -masm=intel -ffixed-r12 $< -o $@

clean:
	rm *.out

tidy:
	rm *.S
