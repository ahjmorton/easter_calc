include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)
FetchContent_MakeAvailable(googletest)

OPTION(BUILD_GTEST ON)
OPTION(BUILD_GMOCK OFF)

ADD_SUBDIRECTORY(lib)
