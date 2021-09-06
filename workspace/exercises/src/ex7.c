/*
 * ex7.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "ex7.h"

void ex7(void)
{
	uint32_t A = 20;
	uint32_t B = 19;

	uint32_t* larger = NULL;

	larger = getLarger(&A, &B);
	printf("Ex7 Data1 = %d (%p), Data 2 = %d (%p), Returned Pointer To %p Value Is %d\n\r", A, (void*)&A, B, (void*)&B, (void*)larger, *larger);
	B = 20;
	larger = getLarger(&A, &B);
	printf("Ex7 Data1 = %d (%p), Data 2 = %d (%p), Returned Pointer To %p Value Is %d\n\r", A, (void*)&A, B, (void*)&B, (void*)larger, *larger);
	B = 21;
	larger = getLarger(&A, &B);
	printf("Ex7 Data1 = %d (%p), Data 2 = %d (%p), Returned Pointer To %p Value Is %d\n\r", A, (void*)&A, B, (void*)&B, (void*)larger, *larger);

}

uint32_t* getLarger(uint32_t* firstNum, uint32_t* secondNum)
{
	//if second is larger return ptr to secondNum
	if(*secondNum>*firstNum)
	{
		return secondNum;
	}
	//if they are equal or first is larger return ptr to firstNum
	return firstNum;
}
