cmake_minimum_required(VERSION 3.15)

project(rainbar)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# file(GLOB SOURCE_FILES "src/*.cpp" "src/*.h")


file(GLOB SOURCE_LIBS
  "src/**/*.h"
  "src/**/*.cpp"
)

file(GLOB SOURCE_FILES
  "src/*.h"
  "src/*.cpp"
)

add_library(libs STATIC ${SOURCE_LIBS})

add_library(Rainbar SHARED ${SOURCE_FILES})

find_package (Threads)
target_link_libraries(Rainbar ${CMAKE_CURRENT_SOURCE_DIR}/rainmeter/x64/Rainmeter.lib)
target_link_libraries(Rainbar libs)
target_link_libraries (Rainbar Threads::Threads)

