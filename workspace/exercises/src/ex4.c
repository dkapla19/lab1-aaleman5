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
	printArray(test1, 4);
	sumOfNextElements(test1, 4);
	printArray(test1, 4);
	printf("Exercise 4 - Case 2\n\r");
	uint16_t test2[] = {100,5,300,51,81};
	printArray(test2, 5);
	sumOfNextElements(test2, 5);
	printArray(test2, 5);

}

void sumOfNextElements(uint16_t* array, size_t size)
{
	//go through each element
	for(size_t i = 0; i<size; i++)
	{
		//add to current element all the elements after it
		for(int j = i+1; j<size; j++)
		{
			*(array+i) += *(array+j);
		}
	}
}

void printArray(uint16_t* array, size_t size)
{
	for(size_t i = 0; i<size; i++)
	{
		printf("%d ", *(array+i));
	}
	printf("\n\r");
}

