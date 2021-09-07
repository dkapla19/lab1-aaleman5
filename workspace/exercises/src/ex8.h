/*
 * ex8.h
 *
 *  Created on: Sep 6, 2021
 *      Author: alemaad1
 */

#ifndef EX8_H_
#define EX8_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void ex8(void);

void bitMaskClear(uint32_t* number, uint32_t mask);

void bitSet(uint32_t* number, uint8_t toSet);

void bitClear(uint32_t* number, uint8_t toSet);

void bitMaskSet(uint32_t* number, uint32_t mask);


#endif /* EX8_H_ */
