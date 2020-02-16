#ifndef HEADER_LIB_EASTER_CALC
#define HEADER_LIB_EASTER_CALC

#include <stdint.h>

typedef struct 
{
  uint8_t month;
  uint8_t day;
} easter_calc_result ;

easter_calc_result easter_calc(uint16_t year);

#endif 
