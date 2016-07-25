cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME_STR TwoViewGeometry)
project(${PROJECT_NAME_STR})

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

# Add 3rd party dependences.
# Add Eigen.
include_directories(
${PROJECT_SOURCE_DIR}/3rdparty/eigen
)

# Add external projects which will be downloaded and built.
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

# Add cmake functions and macros.
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(add_unit_test)
include(add_target)

# Enable the google testing framework.
enable_testing()

# Add targets one by one to have better flexibility when building.
# Add libraries.
ADD_TARGET_LIBRARY(kinematics)
# Add applications.
ADD_TARGET_APP(helloworld)
ADD_TARGET_APP(eigen_example)

