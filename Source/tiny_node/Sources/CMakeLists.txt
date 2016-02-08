if(APPLE)
    set(CMAKE_MACOSX_RPATH ON)
endif()

set(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/tiny_ros_node.cpp
  )

set(INCLUDES_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/../Include
  )

include_directories(${INCLUDES_DIR})
add_library (TinyNode SHARED ${SOURCES})
