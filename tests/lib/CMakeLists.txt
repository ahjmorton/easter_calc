FILE(GLOB SRCS "./*.cpp")

ADD_EXECUTABLE(lib_test ${SRCS})

TARGET_LINK_LIBRARIES(lib_test libeaster_calc gtest gtest_main)

ADD_TEST(lib_test lib_test)
