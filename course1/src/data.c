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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Narayanan
 * @date August 23 2020
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include<data.h>
/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa (int32_t data, uint8_t *ptr,uint32_t base)
{
if ((base >=2) && (base<=16))
{
int i=0;
int count =0;
int rem =0;
bool isNegative = false;
unsigned char str[40];
if(data==0)
{
str[i++]='0';
str[i]='\0';
return (i+1);
}

if(data<0)
{
isNegative=true;
data= -1*data;
}
while(data != 0)
{count++;
rem = data%base;
str[i++]=(rem<=9)?rem+'0':(rem-10)+'a';
data/=base;
}
if(isNegative)
{count++;
str[i++]='g';
}

for(int i=0;i<count;i++)
{ptr[i]=str[count-i-1];
}

return count;
}
return 0;}

int32_t my_atoi(uint8_t*ptr,uint8_t digits,uint32_t base)
{

if((base>=2) && (base<=16))
{
 int32_t i=0;
 int32_t sign = 1;
 int32_t number = 0;
 int32_t power = 1;
 int32_t num =0;
 int d = digits;
 if (ptr[0] == 'g')
    {sign = -1;i=1;}
  else {d+=1;}
if (base == 10)
 {
 while (d!=0)
 { d--;
  if (ptr[i]>='0' && ptr[i]<='9')
    {
       number = number*10 + ptr[i]-48;
       i++;
         }
  else
   {
    break;
   }
 }  number = number*sign;

  return number;
 }
for (;i<digits;i++)
 {
   if (ptr[i] >='0' && ptr[i]<='9')
     {num = (ptr[digits-i])-'0';}
    
   else 
      {num = (ptr[digits-i])-'a'+10;}
  number+= num*power;
  power = power*base;
}
 return number*sign;
}return 0;
}


