cmake_minimum_required(VERSION 2.6)

project(server)
set(ROOT_PATH		${PROJECT_SOURCE_DIR}/../../)
set(SRC_PATH		${ROOT_PATH}/src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14") 

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_PATH})

find_package(Boost COMPONENTS log system thread unit_test_framework REQUIRED)
if (Boost_FOUND)
  add_definitions(-DBOOST_ALL_DYN_LINK)
endif(Boost_FOUND)

set(CORE_PATH		${SRC_PATH}/core)
set(DOMINION_PATH   ${SRC_PATH}/dominion)
set(TEST_PATH		${SRC_PATH}/unittest)
set(EXE_PATH		${SRC_PATH}/server)
include_directories(${Boost_INCLUDE_DIRS} ${SRC_PATH})

set(CORE_SRC 	${CORE_PATH}/log.cpp)
add_library(core SHARED ${CORE_SRC})

set(DOMINION_SRC    ${DOMINION_PATH}/dice.cpp)
					${DOMINION_PATH}/character/attributes.cpp
add_library(dominion SHARED ${DOMINION_SRC})

set(TEST_SRC    ${TEST_PATH}/main.cpp
                ${TEST_PATH}/dominion/attributes.cpp
                ${TEST_PATH}/dominion/dice.cpp
                ${TEST_PATH}/lib/minicsv.cpp)
add_executable(unittest ${TEST_SRC})
target_link_libraries(unittest ${Boost_LIBRARIES} dominion)


set(EXE_SRC ${EXE_PATH}/main.cpp)
add_executable(server ${EXE_SRC})
target_link_libraries(server ${Boost_LIBRARIES} core dominion)




