# This is hacky :(
file(GLOB_RECURSE blueberry_sources ${PROJECT_SOURCE_DIR}/src/*/*.cpp ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp)

include_directories(include)

add_executable(blueberry  ${blueberry_sources})
add_library(blueberry_shared SHARED ${blueberry_sources})
