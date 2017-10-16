set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    pclIoTest.cpp
    pclPassThroughTest.cpp
    pclVoxelTest.cpp
    pclStatisticalOutlierRemovalTest.cpp
    pclMlsSmoothingTest.cpp
    pclFastTriangularTest.cpp
    ../app/pclPassThrough.cpp
    ../app/pclVoxel.cpp
    ../app/pclIo.cpp
    ../app/pclStatisticalOutlierRemoval.cpp
    ../app/pclMlsSmoothing.cpp
    ../app/pclFastTriangular.cpp
)

find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
                                                                                      
target_link_libraries(cpp-test PUBLIC gtest ${PCL_LIBRARIES})
