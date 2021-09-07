/*
 * utils.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "utils.h"

void printUInt16Array(uint16_t* array, size_t size)
{
	for(size_t i = 0; i<size; i++)
	{
		printf("%d ", *(array+i));
	}
	printf("\n\r");
}
