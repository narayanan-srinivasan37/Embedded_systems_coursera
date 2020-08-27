/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file  Stats.h
 * @brief This file contains the function declaration used in the file data.c
 *
 * This file contains the function declaration and their brief description.
 *
 * @author Narayanan S
 * @date 23/08/2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Prints the Statistics parameter
 *
 * It accepts the input array and the length of the array
 * and prints the statistis maximum, minimum, median and mean of the array
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 */
uint8_t my_itoa (int32_t data,uint8_t*ptr, uint32_t base);
/**
 * @brief Prints the Statistics parameter
 *
 * It accepts the input array and the length of the array
 * and prints the statistis maximum, minimum, median and mean of the array
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 */
int32_t my_atoi(uint8_t*ptr,uint8_t digits,uint32_t base);
#endif /* __DATA_H__ */
