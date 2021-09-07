/*
 * ex6.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "ex6.h"

void ex6(void)
{
	int test[] = {0,1,2,3,4,5,6,7,8,9,12,15,20,30,100,126,127};
	printf("Exercise 6.1\n");
	multipleNumbersWrapper(1, 100, 3, 5, test, 17, "6.1");
	printf("Exercise 6.2\n");
	multipleNumbersWrapper(4, 127, 2, 3, test, 17, "6.2");
	printf("Exercise 6.3\n");
	multipleNumbersWrapper(8, 60, 4, 5, test, 17, "6.3");
}

int checkNumber(int boundStart, int boundEnd, int multipleFirst, int multipleSecond, int input)
{
	//verify if input is out of range
	if(input < boundStart || input > boundEnd)
	{
		return OUT_OF_RANGE;
	}
	//verify if input is a multiple of multipleFirst
	if(input%multipleFirst==0)
	{
		//verify if input is also a multiple of multipleSecond
		if(input%multipleSecond==0)
		{
			return MULTIPLE_OF_BOTH;
		}
		return MULTIPLE_OF_FIRST;
	}
	//verify if input is a multiple of multipleSecond
	if(input%multipleSecond==0)
	{
		return MULTIPLE_OF_SECOND;
	}
	//return the number if none of previous case asserted
	return input;
}

void multipleNumbersWrapper(int boundStart, int boundEnd, int multipleFirst, int multipleSecond, int* inputs, size_t size, char* exNum)
{
	int retVal = 0;
	for(size_t i = 0; i<size; i++)
	{
		retVal = checkNumber(boundStart, boundEnd, multipleFirst, multipleSecond, *(inputs+i));
		printf("Ex %s TestVal %d, RetVal %d\n",exNum, *(inputs+i), retVal);
	}
	printf("\n\r");
}
