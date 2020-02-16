#include "libeaster_calc.h"

#define LOOKUP_LENGTH 35
static const char SUNDAY_LETTERS[] = {'A', 'G', 'F', 'E', 'D', 'C', 'B'};
static const char SUNDAY_LETTER_LOOKUP[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C'};
static const uint8_t GOLDEN_NUMBER_LOOKUP[] = {0, 14, 3, 0, 11, 0, 19, 8, 0, 16, 5, 0, 13, 2, 0, 10, 0, 18, 7, 0, 15, 4, 0, 12, 1, 0, 9, 17, 6, 0, 0, 0, 0, 0, 0, 0};

static uint8_t golden_number_calc(uint16_t year) 
{
  uint8_t golden_number = (year + 1) % 19;
  return golden_number == 0 ? 19 : golden_number;
}

static char sunday_letter_calc(uint16_t year) 
{
  uint8_t add = year <= 2099 ? 6 : 5;
  uint16_t fourth_part = year / 4;
  uint8_t letter_index = (year + fourth_part + add) % 7;
  return SUNDAY_LETTERS[letter_index];
} 

static uint8_t golden_number_i_calc(uint8_t golden_number)
{
  for(uint8_t i = 0; i < LOOKUP_LENGTH; i++) {
    if(GOLDEN_NUMBER_LOOKUP[i] == golden_number) {
       return i;
    }
  }
  return 255;
}

static uint8_t date_offset_calc(uint8_t golden_number_i, char sunday_letter)
{
   // +1 here to skip to next sunday if equal
   for(uint8_t offset = golden_number_i + 1;
       offset < LOOKUP_LENGTH;
       offset++) {
     if(SUNDAY_LETTER_LOOKUP[offset] == sunday_letter) {
         return offset;
     }
   }
   return 255;
}

easter_calc_result easter_calc(uint16_t year)
{
  uint8_t golden_number = golden_number_calc(year);
  char sunday_letter = sunday_letter_calc(year);
  uint8_t golden_number_i = golden_number_i_calc(golden_number);
  uint8_t date_offset = date_offset_calc(golden_number_i, sunday_letter);

  easter_calc_result result;
  if(date_offset <= 10) {
    result.month = 3;
    result.day = date_offset + 21;
  } else {
    result.month = 4;
    result.day = date_offset - 10;
  }
  return result;
}

