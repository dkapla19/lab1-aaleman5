/*
 * ex8.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "ex8.h"

void ex8(void)
{
	uint8_t test[] = {0,1,2,3,4,5,6,7};
	uint32_t number = 0xFF;
	for(size_t i = 0; i<8; i++)
	{
		number = 0xFF;
		bitClear(&number,*(test+i));
		printf("Ex 8.1 0xFF Bit Clear %d = 0x%X\n", *(test+i), number);
	}

	uint32_t test2[] = {0x3,0x6,0xC,0x18,0x30,0x60,0xC0};
	for(size_t i = 0; i<7; i++)
	{
		number = 0xFF;
		bitMaskClear(&number,*(test2+i));
		printf("Ex 8.2 0xFF Bit Mask Clear 0x%X = 0x%X\n", *(test2+i), number);
	}

	uint8_t test3[] = {0,1,2,3,4,5,6,7};
	for(size_t i = 0; i<8; i++)
	{
		number = 0xF0;
		bitSet(&number,*(test3+i));
		printf("Ex 8.3 0xF0 Bit Set %d = 0x%X\n", *(test3+i), number);
	}

	uint32_t test4[] = {0x3,0x6,0xC,0x18,0x30,0x60,0xC0,0x180};
	for(size_t i = 0; i<8; i++)
	{
		number = 0xF0;
		bitMaskSet(&number,*(test4+i));
		printf("Ex 8.4 0xF0 Bit Mask Set 0x%X = 0x%X\n", *(test4+i), number);
	}
}

void bitMaskClear(uint32_t* number, uint32_t mask)
{
	*number &= ~mask;
}

void bitSet(uint32_t* number, uint8_t toSet)
{
	*number |= ((uint32_t)0x01)<<toSet;
}

void bitClear(uint32_t* number, uint8_t toSet)
{
	*number &= ~(((uint32_t)0x01)<<toSet);
}

void bitMaskSet(uint32_t* number, uint32_t mask)
{
	*number |= mask;
}
