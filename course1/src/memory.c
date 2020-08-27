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
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t*my_memmove(uint8_t*src, uint8_t*dst, size_t length)
{
 uint8_t temp[100];

 for (unsigned int i =0; i<length; i++)
    {temp[i] = src[i];}

 for (unsigned int i =0; i<length; i++)
    {dst[i] = temp[i];}

 return dst;
}

uint8_t*my_memcopy(uint8_t*src, uint8_t*dst, size_t length)
{
 char *csrc=malloc(35);
 

 for (unsigned int i=0; i<length; i++)
    {csrc[i]=src[i];
     dst[i] =(uint8_t) csrc[i];
    }
free(csrc);
return (uint8_t*)dst;
}

uint8_t*my_memset(uint8_t*src, size_t length,uint8_t value)
{
 uint8_t*ssrc = src;
 for(unsigned int i=0; i<length; i++)
    {ssrc[i] = value;}


 return ssrc;
}
uint8_t* my_memzero(uint8_t*src,size_t length)
{
 uint8_t*zsrc = src;
 for(unsigned int i=0; i<length; i++)
    {zsrc[i] = 0;}
 return zsrc;
}
uint8_t*my_reverse(uint8_t*src, size_t length)
{
size_t i;
for(i=0;i<length/2;++i)
{int tmp=src[i];
src[i]=src[length-1-i];
src[length-1-i]=tmp;
}
return src;
}

int32_t* reserve_words(size_t length)
{ int32_t *ptr =  malloc(sizeof(int32_t)*length);
  if (ptr==NULL)
    return NULL;
  else
   return ptr;
}

void free_words(uint32_t*src)
{ 
  
 free((uint8_t*)src);
 src = NULL;
}
