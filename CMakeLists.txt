cmake_minimum_required(VERSION 3.13)
project(basic_cli)

set(CMAKE_CXX_STANDARD 17)

# Get CLIUtils/CLI11
include(FetchContent)
FetchContent_Declare(
        cli11
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/CLIUtils/CLI11/archive/refs/tags/v2.1.2.zip
)
FetchContent_MakeAvailable(cli11)

include_directories(include)
add_executable(app src/main.cpp)
target_link_libraries(app CLI11::CLI11)

enable_testing()
add_subdirectory(test)