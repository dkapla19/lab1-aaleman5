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

#define ECLIPSE_FLUSH_FIX (1)  //Conditionally Disable Buffering print messages
#define ENABLE_EX1 (1)

int main(void) {
#if ECLIPSE_FLUSH_FIX == (1)
	//WARNING: This doesn't like it if you don't have a new line (ie \n)
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
#endif
#if ENABLE_EX1 == (1)
    ex1();
#endif
	return EXIT_SUCCESS;
}
