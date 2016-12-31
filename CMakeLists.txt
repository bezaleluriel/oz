cmake_minimum_required(VERSION 3.3)
project(oz)


#set(core_sockets src/sockets/Socket.cpp src/sockets/Udp.cpp src/sockets/Tcp.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})
#add_library(sockets ${core_sockets})


set(core_sockets src/sockets/Socket.h src/sockets/Socket.cpp src/sockets/Udp.h src/sockets/Udp.cpp
        src/DriverTest.cpp src/DriverTest.h src/GridNodeTest.cpp src/GridNodeTest.h
        src/StandardCab.cpp src/StandardCab.h src/MaritalStatus.h src/BaseCab.cpp src/BaseCab.h)


add_executable(server ${core_sockets} server.cpp)
add_executable(client ${core_sockets} client.cpp)

target_link_libraries(server   ${Boost_LIBRARIES})
target_link_libraries(client  ${Boost_LIBRARIES})

#set(SOURCE_FILES
#        Socket.cpp Socket.h
#        Udp.cpp Udp.h)
#add_executable(client ${SOURCE_FILES} mainClient.cpp)
#add_executable(server ${SOURCE_FILES} mainServer.cpp)

