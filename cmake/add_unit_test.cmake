# Function of building an unit test, it will automatically collect
# source codes from ${CMAKE_CURRENT_SOURCE_DIR}/test folder.
# The resulting unit test will be named as ${unit_name}_test
function(ADD_UNIT_TEST unit_name)

  file(GLOB TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)

  if (NOT TEST_SRC_FILES)
    RETURN()
  endif()

  set(PROJECT_TEST_NAME ${unit_name}_test)
  add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
  add_dependencies(${PROJECT_TEST_NAME} googletest)

  if(NOT WIN32)
      target_link_libraries(${PROJECT_TEST_NAME}
          ${GTEST_LIBS_DIR}/libgtest.a
          ${GTEST_LIBS_DIR}/libgtest_main.a)
  else()
      target_link_libraries(${PROJECT_TEST_NAME}
          debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
          optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
          )
      target_link_libraries(${PROJECT_TEST_NAME}
          debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
          optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
          )
  endif()

  target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

  target_link_libraries(${PROJECT_TEST_NAME} ${unit_name})

  add_test(${PROJECT_TEST_NAME} ${PROJECT_TEST_NAME})

endfunction(ADD_UNIT_TEST)
