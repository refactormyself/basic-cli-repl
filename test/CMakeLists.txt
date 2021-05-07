### CMakeList for the test

# We are building a separate test (main) so that we are fully isolated from the main app/library (which we are testing)
set(src
        app_tests.cpp
        gtest_main.cpp
)

# the source to be tested will be build as a libary (in this example evrythin is in the .hpp file)
# set(lib_src ../src/somefunctions.cpp)

# Get and Build the Google Test library
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(app_tests ${src})
include_directories("../include")

# add_library(tested ${lib_src})
# target_link_libraries(app_tests tested)

target_link_libraries(app_tests gtest)
target_link_libraries(app_tests gtest_main)

add_test(
        NAME main_tests
        COMMAND app_tests
)
