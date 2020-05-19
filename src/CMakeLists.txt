# This is hacky :(
file(GLOB_RECURSE blueberry_sources ${PROJECT_SOURCE_DIR}/src/*/*.cpp ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp)

include_directories(include)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost REQUIRED COMPONENTS filesystem system date_time)
if(Boost_FOUND)
    message("Boost found")
    include_directories(${Boost_INCLUDE_DIRS})
else(Boost_FOUND)
    message("Does not find Boost")
endif (Boost_FOUND)


add_executable(blueberry  ${blueberry_sources} )
add_library(blueberry_shared SHARED ${blueberry_sources})

target_link_libraries(blueberry ${Boost_LIBRARIES})
target_link_libraries(blueberry_shared ${Boost_LIBRARIES})