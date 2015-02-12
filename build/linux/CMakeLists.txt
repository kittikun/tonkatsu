cmake_minimum_required(VERSION 2.6)

project(server)
set(CMAKE_MODULE_PATH   ${PROJECT_SOURCE_DIR})
set(ROOT_PATH           ${PROJECT_SOURCE_DIR}/../../)
set(SRC_PATH            ${ROOT_PATH}/src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT_PATH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_PATH}/bin)

find_package(Boost COMPONENTS system log thread REQUIRED)
find_package(SQLite3 REQUIRED)

find_library(Dominion_LIBRARIES NAMES dominion PATHS
  $ENV{DOMINIONLIB}/lib
  NO_DEFAULT_PATH)

set(Dominion_INCLUDE $ENV{DOMINIONLIB}/include)

if (Boost_FOUND)
  add_definitions(-DBOOST_ALL_DYN_LINK)

  include_directories(${Boost_INCLUDE_DIRS}
                      ${Dominion_INCLUDE}
                      ${SQLITE3_INCLUDE_DIR})

  set(TONKATSU_SRC  ${SRC_PATH}/main.cpp
                    ${SRC_PATH}/app.cpp
                    ${SRC_PATH}/dominion.cpp
                    ${SRC_PATH}/network/server.cpp
                    ${SRC_PATH}/network/session.cpp
		    ${SRC_PATH}/utility/log.cpp)

  add_executable(tonkatsu ${TONKATSU_SRC})
  target_link_libraries(tonkatsu ${Dominion_LIBRARIES} ${Boost_LIBRARIES} ${SQLITE3_LIBRARY} pthread dl)

endif(Boost_FOUND)
