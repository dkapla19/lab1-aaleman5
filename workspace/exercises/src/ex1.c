/*
 * ex1.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Andres Aleman
 */

#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

void ex1(void){
	char test1[] = { '0','1','2','3','4','5','6','7','8','9'};
	char test2[] = { 'A','B','C','D','E','F','G','H','I'};

	printf("Exercise 1 - Case 1\n\r");
	printCharArray(test1, 10);
	reverseCharArray(test1, 10);
	printCharArray(test1, 10);

	printf("Exercise 2 - Case 2\n\r");
	printCharArray(test2, 9);
	reverseCharArray(test2, 9);
	printCharArray(test2, 9);
}

void printCharArray(char* array, size_t size)
{
	for(size_t i = 0; i<size; i++)
	{
		printf("%c ", *(array+i));
	}
	printf("\n\r");
}

void reverseCharArray(char* array, size_t size)
{
	//half size will be equal to size/2 for even size, and floor(size/2) for odd size
	size_t halfArraySize = size/2;
	for (size_t i=0; i<halfArraySize; i++)
	{
		swapChars(array+i,array+(size-1)-i);
	}
}

void swapChars(char* char1, char* char2)
{
	//store char1 value
	char tmpChar1 = *char1;
	//store char2 value in char1
	*char1 = *char2;
	//store old char1 value in char2
	*char2 = tmpChar1;
}
