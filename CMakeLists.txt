cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME_STR TwoViewGeometry)
project(${PROJECT_NAME_STR})

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

# Add targets one by one to have better flexibility when building.

# Add 3rd party dependences
include_directories(
${PROJECT_SOURCE_DIR}/3rdparty/eigen
)

# Add external projects, now it's gtest.
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

# Add tests
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()

# Add libraries
add_subdirectory(lib/kinematics)
# Add applications
add_subdirectory(app/helloworld)
add_subdirectory(app/eigen_example)

