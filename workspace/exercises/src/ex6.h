/*
 * ex6.h
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#ifndef EX6_H_
#define EX6_H_

#include <stdio.h>
#include <stdlib.h>

#define OUT_OF_RANGE -1
#define MULTIPLE_OF_FIRST -2
#define MULTIPLE_OF_SECOND -3
#define MULTIPLE_OF_BOTH -4

void ex6(void);

int checkNumber(int boundStart, int boundEnd, int multipleFirst, int multipleSecond, int input);

void multipleNumbersWrapper(int boundStart, int boundEnd, int multipleFirst, int multipleSecond, int* inputs, size_t size, char* exNum);

#endif /* EX6_H_ */
