/*
 * ex4.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "ex4.h"

void ex4(void)
{
	printf("Exercise 4 - Case 1\n\r");
	uint16_t test1[] = {10,2,30,40};
	printUInt16Array(test1, 4);
	sumOfNextElements(test1, 4);
	printUInt16Array(test1, 4);
	printf("Exercise 4 - Case 2\n\r");
	uint16_t test2[] = {100,5,300,51,81};
	printUInt16Array(test2, 5);
	sumOfNextElements(test2, 5);
	printUInt16Array(test2, 5);

}

void sumOfNextElements(uint16_t* array, size_t size)
{
	//go through each element backward, except last one
	for(size_t i = size-1; i>0; i--)
	{
		//add next element to current element (which will have the sum of next elements already)
		*(array+i-1) += *(array+i);
	}
}

