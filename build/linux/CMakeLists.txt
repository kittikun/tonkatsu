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

set(CORE_PATH	${SRC_PATH}/Core)
set(DND5_PATH   ${SRC_PATH}/DnD5)
set(TEST_PATH   ${SRC_PATH}/UnitTest)
set(EXE_PATH ${SRC_PATH}/Server)
include_directories(${Boost_INCLUDE_DIRS} ${SRC_PATH} ${TEST_PATH}/include)

set(CORE_SRC 	${CORE_PATH}/Log.cpp)
add_library(core SHARED ${CORE_SRC})

set(DND5_SRC    ${DND5_PATH}/Abilities.cpp
                ${DND5_PATH}/Character.cpp
                ${DND5_PATH}/Dice.cpp
                ${DND5_PATH}/Lore.cpp)
add_library(dnd5 SHARED ${DND5_SRC})


set(TEST_SRC    ${TEST_PATH}/main.cpp
                ${TEST_PATH}/Character.cpp
                ${TEST_PATH}/Dice.cpp
                ${TEST_PATH}/Lore.cpp
                ${TEST_PATH}/include/minicsv.cpp)
add_executable(unittest ${TEST_SRC})
target_link_libraries(unittest ${Boost_LIBRARIES} dnd5)


set(EXE_SRC ${EXE_PATH}/main.cpp)
add_executable(server ${EXE_SRC})
target_link_libraries(server ${Boost_LIBRARIES} core dnd5)




