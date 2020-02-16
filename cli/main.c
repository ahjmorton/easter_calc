#include <stdio.h>
#include <stdlib.h>

#include "libeaster_calc.h"

int main(int argc, char **argv) 
{
  if(argc != 2) {
     return 1;
  }
  
  unsigned int year = atoi(argv[1]);
  easter_calc_result result = easter_calc(year);

  printf("%u-%u\n", result.month, result.day);
  return 0;
}
