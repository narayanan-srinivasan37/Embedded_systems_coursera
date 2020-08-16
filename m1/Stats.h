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
 * @brief This file contains the function declaration used in the file Stats.c
 *
 * This file contains the function declaration and their brief description.
 *
 * @author Narayanan S
 * @date 02/08/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the Statistics parameter
 *
 * It accepts the input array and the length of the array
 * and prints the statistis maximum, minimum, median and mean of the array
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 */
void print_statistics(unsigned char *, int);

/**
 * @brief Prints the array
 *
 * It accepts the input array and the length of the array
 * and prints the all the elements in the array along with its position
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 */

void print_array(unsigned char *,int);

/**
 * @brief Finds the maximum element in the array
 *
 * It accepts the input array and the length of the array
 * and finds the maximum value in the array
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 * @returns the maximum value in the array
 */
unsigned char find_maximum(unsigned char *,int);

/**
 * @brief Finds the maximum element in the array
 *
 * It accepts the input array and the length of the array
 * and finds the manimum value in the array
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 * @returns the minimum value in the array
 */
unsigned char find_minimum(unsigned char *,int);

/**
 * @brief Finds the median of the array
 *
 * It accepts the input array and the length of the array
 * and finds the median value in the array
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 * @returns the median value in the array
 */
unsigned char find_median(unsigned char *,int);

/**
 * @brief Finds the mean of the array
 *
 * It accepts the input array and the length of the array
 * and finds the mean value in the array
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 * @returns the mean value in the array
 */
unsigned char find_mean(unsigned char *,int);

/**
 * @brief Sorts the array
 *
 * It accepts the input array and the length of the array
 * and sorts the array in descending array from maximum to minimum
 *
 * @param char variable that accepts the input array
 * @param int variable that accepts the length of the array
 */
void sort_array(unsigned char *,int);





#endif /* __STATS_H__ */
