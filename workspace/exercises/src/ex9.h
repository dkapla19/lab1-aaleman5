/*
 * ex9.h
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#ifndef EX9_H_
#define EX9_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ERROR_CODE -1
#define SUCCESS 1
#define THRESHOLD 400

typedef struct {
    uint32_t first;    /**< first dimension value */
    uint32_t second; /**< second dimension value */
}myCustomStruct_t;

void ex9(void);

int initCustomStructure(myCustomStruct_t* myCustomStruct, uint32_t first, uint32_t second);

#endif /* EX9_H_ */
