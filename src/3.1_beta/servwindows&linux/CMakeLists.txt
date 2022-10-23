cmake_minimum_required(VERSION 3.0.0)
project(serv VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(serv serv.cpp interudp4.cpp Wincommon.h Winudp4.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
