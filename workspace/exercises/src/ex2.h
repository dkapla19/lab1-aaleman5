/*
 * ex2.h
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#ifndef EX2_H_
#define EX2_H_

//Float definition of PI
//https://embedded.fm/blog/2016/4/12/ew-floating-point
#define PI 3.141592F

#include <stdio.h>
#include <stdlib.h>

void ex2(void);

void getArea(const float* radius, float* area);

void printRadiusArea(const float* radius, const float* area);

#endif /* EX2_H_ */
