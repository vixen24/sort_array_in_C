/******************************************************************************
 * Copyright (C) 2021 by William Idakwo
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. William Idakwo is not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Performs basic statistical analysis on a character array and prints the result 
 * This programs calculates the mean, median, minimum and maximum of elements in a dataset and prints the result . 
 *
 * Char datatype can hold up of 1 byte. That means, if the result of a math operation is greater than 255, there will be   
 * an overflow, a technique was implemented to handle this in the find_mean function.
 * We use the modulus operator to obtain the remainder(overflow) after a division, then add all the remainders and divide the sum by the  
 * number of elements in the array you will be able to recover the lost values. Look up the find_mean function. 
 * 
 * @author Add William Idakwo
 * @date 03-02-2021
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define LENGTH (40)
/* Function declarations */
unsigned char find_mean(unsigned char *l,    unsigned int i); 
unsigned char find_median(unsigned char  *l,  unsigned int i);
unsigned char find_minimum(unsigned char *l, unsigned int i);
unsigned char find_maximum(unsigned char *l, unsigned int i);
unsigned char *sort_array(unsigned char *l, unsigned int i);
void print_array(unsigned char *l,  unsigned int i);
void print_statistics(unsigned char mean, unsigned char med, unsigned char min, unsigned char max);

int main(void) {
    /* A character array with values ranging from 2 to 250 */
    unsigned char test[LENGTH] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                 114, 88,   45,  76, 123,  87,  25,  23,
                                 200, 122, 150, 90,   92,  87, 177, 244,
                                 201,   6,  12,  60,   8,   2,   5,  67,
                                   7,  87, 250, 230,  99,   3, 100,  90};

    /*Global Variable Declarations */  
    unsigned char med;
    unsigned char mean;
    unsigned char min;
    unsigned char max;
    unsigned char *sort;

    /*Statistics and Printing Functions*/  
    printf("\n\n\n          Original Array\n");
    print_array(test,LENGTH); //prints test array as above
    sort = sort_array(test, LENGTH); //sorts array from the largest to the smallest number 
    mean = find_mean(test, LENGTH); //finds the mean of an array
    med = find_median(sort, LENGTH); //finds the median of an array
    min = find_minimum(sort, LENGTH); //finds the minimum of an array
    max = find_maximum(sort, LENGTH); //finds the maximum of an array
    print_statistics(mean, med, min, max); //prints the mean, median, minimum and maximum
    printf("            Sorted Array\n");
    print_array(sort,LENGTH); //prints sort array
    return 0;
}

/*calculate the mean of an array*/
unsigned char find_mean(unsigned char *arr, unsigned int size){
    unsigned char avg = 0;              //Holds the Average
    unsigned static char carry[] = {0}; //Creates an array to hold carry; char type holds up to a byte, sum of elements is more than a byte
    unsigned char carr = 0;             //Holds the final 
    unsigned char count = 0;            //a counter for the carry array
    for (int i = 0; i < size; i++){   
        avg += (*(arr + i)/size); 
        if((carry[count] + (*(arr + i)%size)) > 254 ){ //checks if carry is more than a byte
            carry[count+1]= (*(arr + i)%size);         // 
            count++;
        }
        carry[count] += (*(arr + i)%size); //Add the carry
    }
    for(int i = 0; i <= count; i++){     
        carr += (carry[i]/size);
    }
    return (avg+carr);
}

/*This function finds the median of an array*/
unsigned char find_median(unsigned char *arr, unsigned int size){
    unsigned char median;
    if(size%2 == 0){		//if number of elements are even 
	    median = ((*(arr +((size/2)-1)) + *(arr + (size/2)))/2);
        return median;
    }else{ 			//if number of elements are odd
        median = *(arr + (size/2));
	    return median;
    }
}

//This function finds the maximum of an array
unsigned char find_maximum(unsigned char *arr, unsigned int size){
    return *(arr);
}

//This function finds the minimum of an array
unsigned char find_minimum(unsigned char *arr, unsigned int size){
    return *(arr +(size - 1));
}

//This function sorts an array from the largest to the smallest
unsigned char *sort_array(unsigned char *arr, unsigned int size){
    unsigned char hold = 0;
    unsigned static char sorted[] = {0};
    for (int i = 0; i < size; i++){
        sorted[i] = *(arr + i);
    }
    for(int i =0; i < size; i++){   
        for(int j = i +1; j < size; j++){
            if(sorted[i] < sorted[j]){
                 hold = sorted[i];
                 sorted[i] = sorted[j];
                 sorted[j]= hold;       
             }
         }
    }
    return sorted;
}

//This function prints any given array
void print_array(unsigned char  *arr, unsigned int size){
    unsigned char count =1;
    printf("------------------------------------\n");
    for(int i =0; i < size; i++){
        printf("%d\t", *(arr + i));
        count++;
        if(count > 5){printf("\n"); count = 1;}
    }
    printf("\n\n");
}

//This function prints the mean, median, minimum and the maximum
void print_statistics(unsigned char mean, unsigned char med, unsigned char min,unsigned char max){
    printf("\n             Analytics");
    printf("\n----------------------------------\n");
    printf("The mean of the Dataset is %d", mean);
    printf("\n----------------------------------\n");
    printf("The median of the Dataset is %d", med);
    printf("\n----------------------------------\n");
    printf("The minimum of the Dataset is %d", min);
    printf("\n----------------------------------\n");
    printf("The maximum of the Dataset is %d", max);
    printf("\n----------------------------------\n");
    printf("\n\n");
}

