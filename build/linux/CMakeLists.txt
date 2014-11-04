cmake_minimum_required(VERSION 2.6)

project(stratumLib)
set(ROOT_PATH   ${PROJECT_SOURCE_DIR}/../../)
set(SRC_PATH	${ROOT_PATH}/src)
set(OUT_PATH    ${PROJECT_SOURCE_DIR}/out)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11") 


set(CORE_SRC	${SRC_PATH}/Core)
set(CORE_LIB_SRC 	${CORE_SRC}/log.cpp)

find_package(Boost COMPONENTS log system thread REQUIRED)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  set(EXTRA_LIBS ${Boost_LIBRARIES})
  add_definitions(-DBOOST_ALL_DYN_LINK)
endif(Boost_FOUND)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_PATH})

add_library(Core SHARED ${CORE_LIB_SRC})