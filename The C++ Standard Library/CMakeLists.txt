cmake_minimum_required(VERSION 2.8)
project(The_C++_Standard_Library)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 11)

include_directories(ch06)

file(GLOB_RECURSE ALL_SRCS "*.cc")
foreach(FILE_PATH ${ALL_SRCS})
  get_filename_component(DIRECTORY_PATH ${FILE_PATH} PATH)
  get_filename_component(DIRECTORY_NAME ${DIRECTORY_PATH} NAME)
  get_filename_component(FILENAME ${FILE_PATH} NAME_WE)
  set(EXEC "${DIRECTORY_NAME}${FILENAME}")
  add_executable(${EXEC} ${FILE_PATH})
endforeach(FILE_PATH)

target_link_libraries(ch05sharedptr3 rt)
