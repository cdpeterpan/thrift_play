CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_C_COMPILER gcc)
PROJECT(client)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


INCLUDE_DIRECTORIES(./gen-cpp)
INCLUDE_DIRECTORIES(/usr/local/include/thrift)

SET(SRC_LIST client.cpp
            ./gen-cpp/Serv.cpp
            ./gen-cpp/student_types.cpp)

ADD_EXECUTABLE(client ${SRC_LIST})
target_link_libraries(client -Wl,--start-group z rt ssl thrift -Wl,--end-group)