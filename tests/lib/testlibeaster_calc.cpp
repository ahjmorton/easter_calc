#include "gtest/gtest.h"

extern "C" {
  #include "libeaster_calc.h"
}

TEST(Library, works_for_2020) {
  easter_calc_result result = easter_calc(2020);
  ASSERT_EQ(result.month, 4);
  ASSERT_EQ(result.day, 12);
}
