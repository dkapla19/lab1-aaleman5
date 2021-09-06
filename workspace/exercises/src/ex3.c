/*
 * ex3.c
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#include "ex3.h"

void ex3(void){
    point_t firstPoint = {
            0.000000, // x
			0.000000, // y
    };
    point_t secondPoint = {
			0.000000, // x
			1.000000, // y
    };

	float distance = 0;
	printf("Exercise 3 - Case 1\n\r");
	getDistance(&firstPoint, &secondPoint, &distance);
	printPointsDistance(&firstPoint, &secondPoint, &distance);

	firstPoint.x = 0.0;
	firstPoint.y = 0.0;
	secondPoint.x = 1.0;
	secondPoint.y = 1.0;

	printf("Exercise 3 - Case 2\n\r");
	getDistance(&firstPoint, &secondPoint, &distance);
	printPointsDistance(&firstPoint, &secondPoint, &distance);
}

void getDistance(const point_t* firstPoint, const point_t* secondPoint, float* distance)
{
	//Get the x difference squared
	float xDiffSquared = (secondPoint->x-firstPoint->x)*(secondPoint->x-firstPoint->x);
	//Get the y difference squared
	float yDiffSquared = (secondPoint->y-firstPoint->y)*(secondPoint->y-firstPoint->y);
	//square root using float as input/output
	*distance =  sqrtf(xDiffSquared+yDiffSquared);
}

void printPointsDistance(const point_t* firstPoint, const point_t* secondPoint, const float* distance)
{
	printf("(%f, %f) to (%f, %f) Distance %f\n\r", firstPoint->x, firstPoint->y, secondPoint->x, secondPoint->y, *distance);
}
