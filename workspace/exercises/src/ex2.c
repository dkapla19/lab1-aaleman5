/*
 * ex2.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "ex2.h"

void ex2(void){
	float radius = 1.000000f;
	float area = 0;
	printf("Exercise 2 - Case 1\n\r");
	getArea(&radius, &area);
	printRadiusArea(&radius,&area);
	radius = 2.245f;
	printf("Exercise 2 - Case 2\n\r");
	getArea(&radius, &area);
	printRadiusArea(&radius,&area);
}

void getArea(const float* radius, float* area)
{
	*area = PI*(*radius)*(*radius);
}

void printRadiusArea(const float* radius, const float* area)
{
	//TODO change to seven significant digits
	printf("Radius %f, Area %f\n\r", *radius, *area);
}

