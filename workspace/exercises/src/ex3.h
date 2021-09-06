/*
 * ex3.h
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#ifndef EX3_H_
#define EX3_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;    /**< first dimension value */
    float y; /**< second dimension value */
}point_t;

void ex3(void);

void getDistance(const point_t* firstPoint, const point_t* secondPoint, float* distance);

void printPointsDistance(const point_t* firstPoint, const point_t* secondPoint, const float* distance);

#endif /* EX3_H_ */
