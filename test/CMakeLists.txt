set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    pclIoTest.cpp
    pclCloudViewerTest.cpp
    pclVoxelTest.cpp
    ../app/pclIo.cpp
    ../app/pclCloudViewer.cpp
    ../app/pclVoxel.cpp
)

find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
                                                                                      
target_link_libraries(cpp-test PUBLIC gtest ${PCL_LIBRARIES})
