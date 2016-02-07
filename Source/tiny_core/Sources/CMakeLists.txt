if(APPLE)
    set(CMAKE_MACOSX_RPATH ON)
endif()

set(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/tiny_ros_core.cpp
  )
set(INCLUDES
  ${CMAKE_CURRENT_SOURE_DIR}../Include/tiny_ros_core.h
  )

add_executable(tiny_ros_core tiny_ros_core.cpp ${INCLUDES})
