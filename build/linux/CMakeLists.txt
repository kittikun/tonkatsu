cmake_minimum_required(VERSION 2.6)

project(server)
set(ROOT_PATH   ${PROJECT_SOURCE_DIR}/../../)
set(SRC_PATH	${ROOT_PATH}/src)
set(OUT_PATH    ${PROJECT_SOURCE_DIR}/out)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11") 

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_PATH})

set(CORE_PATH	${SRC_PATH}/Core)
set(CORE_SRC 	${CORE_PATH}/log.cpp)
add_library(core SHARED ${CORE_SRC})

set(DND5_PATH   ${SRC_PATH}/Bible)
set(DND5_PATH_SRC    ${DND5_PATH}/d20.cpp)
add_library(dnd5 SHARED ${BIBLE_SRC})

set(EXE_PATH ${SRC_PATH}/Server)
set(EXE_SRC ${EXE_PATH}/main.cpp)
add_executable(server ${EXE_SRC})

find_package(Boost COMPONENTS log system thread REQUIRED)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS} ${SRC_PATH})
  #set(EXTRA_LIBS ${Boost_LIBRARIES})
  target_link_libraries(server ${Boost_LIBRARIES} core dnd5)
  add_definitions(-DBOOST_ALL_DYN_LINK)
endif(Boost_FOUND)



