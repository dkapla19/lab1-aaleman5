/*
 * ex5.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "ex5.h"

void ex5(void)
{
	printf("Exercise 5 - Case 1\n\r");
	uint16_t test1[] = {10,2,30,40};
	printUInt16Array(test1, 4);
	sumOfPrevElements(test1, 4);
	printUInt16Array(test1, 4);
	printf("Exercise 5 - Case 2\n\r");
	uint16_t test2[] = {100,5,300,51,81};
	printUInt16Array(test2, 5);
	sumOfPrevElements(test2, 5);
	printUInt16Array(test2, 5);

}

void sumOfPrevElements(uint16_t* array, size_t size)
{
	//go through each element, except first element
	for(size_t i = 1; i<size; i++)
	{
		//add the previous element (which will have the sum of all it's prev already)
		*(array+i) += *(array+i-1);
	}
}

