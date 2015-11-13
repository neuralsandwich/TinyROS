cmake_minimum_required (VERSION 2.8.7)

project (xmlrpc-test)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything -std=c++11 -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded")

include(ExternalProject)
ExternalProject_Add(XmlRpcppDownload
  GIT_REPOSITORY https://github.com/jaredsburrows/XmlRpcpp.git
  PREFIX External
  CONFIGURE_COMMAND ""
  CMAKE_COMMAND ""
  BUILD_COMMAND "make"
  INSTALL_COMMAND ""
  TEST_COMMAND ""
  BUILD_IN_SOURCE 1
  )

SET(XMLRPCPP_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/External/src/XmlRpcppDownload/src)
SET(XMLRPCPP_LIB_DIR ${CMAKE_CURRENT_BINRARY_DIR}External/src/XmlRpcppDownload)

add_library(XmlRpcpp STATIC IMPORTED)
set_target_properties(XmlRpcpp PROPERTIES IMPORTED_LOCATION ${XMLRPCPP_LIB_DIR}/libXmlRpc.a)

include_directories(${XMLRPCPP_INCLUDE_DIR})
add_executable(server server.cpp)
add_executable(client client.cpp)
target_link_libraries(server XmlRpcpp)
target_link_libraries(client XmlRpcpp)
add_dependencies(server XmlRpcppDownload)
add_dependencies(client XmlRpcppDownload)
