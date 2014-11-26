cmake_minimum_required(VERSION 2.6)

project(server)
set(ROOT_PATH           ${PROJECT_SOURCE_DIR}/../../)
set(SRC_PATH            ${ROOT_PATH}/src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT_PATH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_PATH}/bin)

find_package(Boost COMPONENTS chrono system filesystem log thread unit_test_framework REQUIRED)

if (Boost_FOUND)
  add_definitions(-DBOOST_ALL_DYN_LINK -DDOMINION_DATAGEN -DSQLITE_THREADSAFE)

  set(DOMINION_PATH       ${SRC_PATH}/dominion)
  set(TEST_PATH           ${SRC_PATH}/unittest)
  set(EXE_PATH            ${SRC_PATH}/server)
  include_directories(${Boost_INCLUDE_DIRS}
                      ${SRC_PATH}
                      ${SRC_PATH}/dominion/lib)

  set(DOMINION_SRC    ${DOMINION_PATH}/api.cpp
                      ${DOMINION_PATH}/database.cpp
                      ${DOMINION_PATH}/dice.cpp
                      ${DOMINION_PATH}/character/attributes.cpp
                      ${DOMINION_PATH}/character/perk.cpp
					  ${DOMINION_PATH}/character/skill.cpp
					  ${DOMINION_PATH}/impl/api_impl.cpp
					  ${DOMINION_PATH}/impl/character_impl.cpp
					  ${DOMINION_PATH}/impl/database_impl.cpp
					  ${DOMINION_PATH}/impl/perk_impl.cpp
					  ${DOMINION_PATH}/impl/skill_impl.cpp
					  ${DOMINION_PATH}/lib/sqlite/shell.c
					  ${DOMINION_PATH}/lib/sqlite/sqlite3.c)
  add_library(dominion SHARED ${DOMINION_SRC})

  set(TEST_SRC    ${TEST_PATH}/main.cpp
                  ${TEST_PATH}/dominion/api.cpp
                  ${TEST_PATH}/dominion/attributes.cpp
                  ${TEST_PATH}/dominion/dice.cpp
		          ${TEST_PATH}/dominion/perk.cpp
				  ${TEST_PATH}/dominion/skill.cpp
                  ${TEST_PATH}/lib/minicsv.cpp)
  add_executable(unittest ${TEST_SRC})
  target_link_libraries(unittest dominion ${Boost_LIBRARIES} dl)

  set(EXE_SRC ${EXE_PATH}/main.cpp
              ${EXE_PATH}/utility/log.cpp)
  add_executable(server ${EXE_SRC})
  target_link_libraries(server ${Boost_LIBRARIES} dominion)

endif(Boost_FOUND)
