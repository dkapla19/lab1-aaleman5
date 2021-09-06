/*
 ============================================================================
 Name        : exercises.c
 Author      : Andres Aleman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"
#include "ex2.h"
#include "ex3.h"

#define ECLIPSE_FLUSH_FIX (1)  //Conditionally Disable Buffering print messages
#define ENABLE_EX1 (0)
#define ENABLE_EX2 (0)
#define ENABLE_EX3 (1)

int main(void) {
#if ECLIPSE_FLUSH_FIX == (1)
	//WARNING: This doesn't like it if you don't have a new line (ie \n)
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
#endif
#if ENABLE_EX1 == (1)
    ex1();
#endif
#if ENABLE_EX2 == (1)
    ex2();
#endif
#if ENABLE_EX3 == (1)
    ex3();
#endif
	return EXIT_SUCCESS;
}