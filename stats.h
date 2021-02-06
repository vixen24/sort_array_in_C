/******************************************************************************
 * Copyright (C) 2021 by William Idakwo
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. William Idakwo is not liable for any misuse of this material. 
 * 
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief A header file 
 *
 * Includes a standard C Predefined MACRO, declarations, functions and description of the source file(stats.c)
 *
 * @author William Idakwo
 * @date 03-02-2021 
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/*  Declarations and Function */ 
unsigned char find_mean(unsigned char *l,    unsigned int i); // the mean of an array
unsigned char find_median(unsigned char  *l,  unsigned int i);//
unsigned char find_minimum(unsigned char *l, unsigned int i);
unsigned char find_maximum(unsigned char *l, unsigned int i);
unsigned char *sort_array(unsigned char *l, unsigned int i);
void print_array(unsigned char *l,  unsigned int i);
void print_statistics(unsigned char a, unsigned char b, unsigned char c, unsigned char d);

/** find_mean
 * @brief <Calculates the mean of elements>
 * * <To get the mean: divide each element of the array by the total number element in array>
 *
 * We will find the sum of the division of each element by the total number of elements in the array. To account for   
 * loses as a result of the fact that the char datatype is a byte and also characters do not store floating numbers
 * we will find the sum of all the carry(remainders) and divide by the total number of elements in the array. 
 * The mean is the the sums of both the carry and the average. 
 *
 * @param <unsigned char *l> <Pointer to the test array
 * @param <unsigned int i> Number of characters in the array
 *
 * @return <mean> <average of the elements provided>
 */

/** find_median
 * @brief Calculates the median of elements
 *
 * Gets the median from the sort array. If the number is elements in the dataset is even, median is calculated by 
 * dividing the sum of the two middle numbers by 2 OTHERWISE the median is the middle when arranged in either ascending or 
 * descending order of magnitude.
 *
 * @param <unsigned char *l> <Pointer to the sorted array>
 * @param <unsigned int i>   <Number of elements in the test array>
 *
 * @return median of the elements provided 
 */

/** find_minimum
 * @brief Calculates the minimum value elements in the character array
 *
 * Arrange the elements of the character array in descending order using the sort_array function, 
 * Take the last element of the character array. 
 *
 * @param <unsigned char *l> Pointer to the sorted array
 * @param <unsigned int i>   Number of elements in the test array
 *
 * @return minimum element of the character array
 */

/** find maximum
 * @brief Calculates the maximum value elements in the character array
 *
 * Gets the maximum from from the sorted array. 
 *
 * @param <unsigned char *l> Pointer to the array
 * @param <unsigned int i>   Number of elements in the test array
 *
 * @return maximum element of the character array
 */

/** sort_array
 * @brief Sorts the elements of the character array in descending order
 *
 * Arranges the elements of the character array in descending order. Instead of changing the array passed to it
 * it returns a new array of sorted elements 
 *
 * @param <unsigned char *l> Pointer to the test array
 * @param <unsigned int i>   Number of elements in the test array
 *
 * @return Pointer to sorted array
 */

/** print_array
 * @brief Prints a character array
 *
 * Prints any charater array given the size of array and a pointer to the Array.
 *
 * @param <unsigned char *l> Pointer to an array
 * @param <unsigned int i>   Number of elements in the test array
 *
 * @return void
 */

/** print_statistics
 * @brief Prints the values
 *
 * Prints the values of the elements pass to it. 
 *
 * @param unsigned char a  The mean value
 * @param unsigned char b  The median value
 * @param unsigned char c  The minimum value
 * @param unsigned char d  The maximum value
 *
 * @return void
 */
#endif /* __STATS_H__ */
