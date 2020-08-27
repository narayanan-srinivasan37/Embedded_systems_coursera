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
 * @file Stats.c
 * This file provides statistical value of the array
 * This file takes the input as an array and the length of the array
 * and provides mean , median, maximum, minimum value and sorts the array
 * in the descending array
 * @author Narayanan S
 * @date 01/08/2020
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

#ifdef VERBOSE
void print_array(unsigned char *u,int q)
{
for(int i=0;i<q;i++)
 {
  PRINTF("Array[%d]:%d \n",i,u[i]);
 }
}
#endif


 

/*
void print_statistics (unsigned char *t,int l)
{
unsigned char data[SIZE];
unsigned char maximum, minimum, mean,median;
for(int i=0;i<l;i++)
{
 data[i]=*t;
 t++;
}
printf("\n");
 maximum= find_maximum(data,l);
 minimum=find_minimum(data,l);
 mean= find_mean(data,l);
 median=find_median(data,l);

 PRINTF("Maximum number in the array : %d \n",maximum);
 PRINTF("Minimum number in the array : %d \n",minimum);
 PRINTF("Mean in the array : %d \n",mean);
 PRINTF("Median in the array : %d \n", median);
}

unsigned char find_maximum(unsigned char *t, int l)
{
 int max=t[0];
 for (int i=1;i<l;i++)
 {
  if (t[i]>max)
  { 
    max=t[i];
  }

 }
 return max;
}
*/
unsigned char find_minimum(unsigned char *m, int e)
{
 int min=m[0];
 for (int i=1;i<e;i++)
 {
  if (m[i]<min)
  { 
    min=m[i];
    
  }
 }
 return min;
}

unsigned char find_mean(unsigned char *s, int n)
{
 int mean=0;
 
 for(int i=0;i<n;i++)
  {
   mean+=s[i];
   

  }
 mean=(mean/n);

 return mean;
}

unsigned char find_median(unsigned char *b, int g)
{ 
unsigned char data[SIZE];
char median;
int a;
for(int i=0;i<g;i++)
{
 data[i]=*b;
 b++;
}
sort_array(data,g);
a=(g/2);
 if (g%2==0)
 { 
 median=((data[a] + data[a+1])/2);
 }
 
 else 
 {
 median=(data[a]);
 } 
return median;
}

void sort_array(unsigned char *arr, int w)
{
int temp;

 for(int i=0;i<w;i++)
  {
    for (int j=i+1;j<w;j++)
     {
       if(arr[j]>arr[i])
	{
	 temp=arr[i];
	 arr[i]=arr[j];
	 arr[j]=temp;
	}
      }
  }
}
