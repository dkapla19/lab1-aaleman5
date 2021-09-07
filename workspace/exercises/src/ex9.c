/*
 * ex9.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "ex9.h"

void ex9(void){
	myCustomStruct_t myCustomStruct = {
            1, // first
			2, // second
    };

	uint32_t testFirst[] = {400,401,400,401};
	uint32_t testSecond[] = {400,401,401,400};
	int retVal = 0;
	for(size_t i = 0; i<4; i++)
	{
		if(SUCCESS==(retVal = initCustomStructure(&myCustomStruct, testFirst[i], testSecond[i])))
		{
			printf("Ex 9 Data1 %d, Data2 %d | myCustomStructure Data1 %d Data2 %d\n", testFirst[i], testSecond[i], myCustomStruct.first, myCustomStruct.second);
		}
		else
		{
			printf("Ex 9 Data1 %d, Data2 %d | initCustomStructure error return code %d\n", testFirst[i], testSecond[i], retVal);
		}
	}
}

int initCustomStructure(myCustomStruct_t* myCustomStruct, uint32_t first, uint32_t second)
{
	if (first>THRESHOLD && second>THRESHOLD)
	{
		myCustomStruct->first = first;
		myCustomStruct->second = second;
		return SUCCESS;
	}
	return ERROR_CODE;
}
