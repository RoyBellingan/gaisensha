cmake_minimum_required(VERSION 2.6)
project(gaisensha)
find_package(Qt4 REQUIRED)

enable_testing()

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(gaisensha_SRCS gaisensha.cpp main.cpp)

qt4_automoc(${gaisensha_SRCS})
add_executable(gaisensha ${gaisensha_SRCS})
target_link_libraries(gaisensha ${QT_QTCORE_LIBRARY})

add_subdirectory(tests)

install(TARGETS gaisensha RUNTIME DESTINATION bin)
