include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(gaisenshaTest_SRCS gaisenshaTest.cpp)

qt4_automoc(${gaisenshaTest_SRCS})
add_executable(gaisenshaTest ${gaisenshaTest_SRCS})
add_test(gaisenshaTest gaisenshaTest)
target_link_libraries(gaisenshaTest ${QT_QTCORE_LIBRARY} ${QT_QTTEST_LIBRARY})
