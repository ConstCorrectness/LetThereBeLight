include(FetchContent)
FetchContent_Declare(
  # e60666bfebe459a84f8b4964cea0b150a04d0e39 is the commit hash for v1.17.0
  googletest
  URL https://github.com/google/googletest/archive/e60666bfebe459a84f8b4964cea0b150a04d0e39.zip
)


# idk why windows needs this, check the googletest docs
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


FetchContent_MakeAvailable(googletest)

