CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_C_COMPILER gcc)
PROJECT(server)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


INCLUDE_DIRECTORIES(.)

SET(SRC_LIST Serv_server.skeleton.cpp
			Serv.cpp
			student_types.cpp)

ADD_EXECUTABLE(server ${SRC_LIST})
target_link_libraries(server -Wl,--start-group thrift -Wl,--end-group)