cmake_minimum_required(VERSION 2.6)

project(server)
set(ROOT_PATH   ${PROJECT_SOURCE_DIR}/../../)
set(SRC_PATH	${ROOT_PATH}/src)
set(OUT_PATH    ${PROJECT_SOURCE_DIR}/out)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11") 

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_PATH})

find_package(Boost COMPONENTS log system thread unit_test_framework REQUIRED)
if (Boost_FOUND)
  add_definitions(-DBOOST_ALL_DYN_LINK)
endif(Boost_FOUND)

set(CORE_PATH	${SRC_PATH}/core)
set(DND5_PATH   ${SRC_PATH}/dnd5)
set(TEST_PATH   ${SRC_PATH}/unittest)
set(EXE_PATH ${SRC_PATH}/server)
include_directories(${Boost_INCLUDE_DIRS} ${SRC_PATH} ${TEST_PATH}/include)

set(CORE_SRC 	${CORE_PATH}/log.cpp)
add_library(core SHARED ${CORE_SRC})

set(DND5_SRC    ${DND5_PATH}/abilities.cpp
                ${DND5_PATH}/character.cpp
                ${DND5_PATH}/dice.cpp
                ${DND5_PATH}/lore.cpp)
add_library(dnd5 SHARED ${DND5_SRC})


set(TEST_SRC    ${TEST_PATH}/main.cpp
                ${TEST_PATH}/character.cpp
                ${TEST_PATH}/dice.cpp
                ${TEST_PATH}/lore.cpp
                ${TEST_PATH}/lib/minicsv.cpp)
add_executable(unittest ${TEST_SRC})
target_link_libraries(unittest ${Boost_LIBRARIES} dnd5)


set(EXE_SRC ${EXE_PATH}/main.cpp)
add_executable(server ${EXE_SRC})
target_link_libraries(server ${Boost_LIBRARIES} core dnd5)




