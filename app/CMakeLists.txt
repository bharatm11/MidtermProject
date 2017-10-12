
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    
)
find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable(shell-app main.cpp pclIo.cpp pclCloudViewer.cpp pclVoxel.cpp pclPassThrough.cpp)
target_link_libraries (shell-app ${PCL_LIBRARIES})
