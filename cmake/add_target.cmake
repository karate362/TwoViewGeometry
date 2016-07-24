# Macro of adding a library and it's include path to build.
macro(ADD_TARGET_LIBRARY unit_name)

  include_directories(${PROJECT_SOURCE_DIR}/lib/${unit_name}/include)
 
  add_subdirectory(${PROJECT_SOURCE_DIR}/lib/${unit_name})

endmacro(ADD_TARGET_LIBRARY)

# Macro of building a library, it will automatically collect
# source codes from lib/${unit_name}/src and lib/${unit_name}/test
# for building library and unit tests.
# Linked libraries can be added after the argument "unit_name"
macro(BUILD_TARGET_LIBRARY unit_name)

  set(PROJECT_NAME ${unit_name})

  project(${PROJECT_NAME})

  set(${PROJECT_NAME}_include_path ${CMAKE_CURRENT_SOURCE_DIR}/include)

  include_directories(${${PROJECT_NAME}_include_path})

  file(GLOB TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

  if (NOT TEST_SRC_FILES)
    RETURN()
  endif()

  add_library(${PROJECT_NAME} ${TEST_SRC_FILES})

  # Add additional dependences

  foreach(f ${ARGN})
    target_link_libraries(${f})
  endforeach()

  ADD_UNIT_TEST(${PROJECT_NAME})

endmacro(BUILD_TARGET_LIBRARY)

# Macro of adding an app, notice that it will not add
# additional include paths.
macro(ADD_TARGET_APP unit_name)
 
  add_subdirectory(${PROJECT_SOURCE_DIR}/app/${unit_name})

endmacro(ADD_TARGET_APP)

# Macro of building an app, it will automatically collect
# source codes from app/${unit_name}/src and app/${unit_name}/test
# for building library and unit tests.
# Linked libraries can be added after the argument "unit_name"
macro(BUILD_TARGET_APP unit_name)

  set(PROJECT_NAME ${unit_name})

  project(${PROJECT_NAME})

  set(${PROJECT_NAME}_include_path ${CMAKE_CURRENT_SOURCE_DIR}/include)

  include_directories(${${PROJECT_NAME}_include_path})

  file(GLOB TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

  if (NOT TEST_SRC_FILES)
    RETURN()
  endif()

  add_executable(${PROJECT_NAME} ${TEST_SRC_FILES})

  # Add additional dependences

  foreach(f ${ARGN})
    target_link_libraries(${f})
  endforeach()

  ADD_UNIT_TEST(${PROJECT_NAME})

endmacro(BUILD_TARGET_APP)
