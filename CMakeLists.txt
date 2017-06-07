cmake_minimum_required(VERSION 2.8)

set(LINKER_FLAGS_RELEASELTO "-Wl,--as-needed -Wl,--allow-shlib-undefined")
set(CMAKE_EXE_LINKER_FLAGS_RELEASELTO "${LINKER_FLAGS_RELEASELTO}")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASELTO "${LINKER_FLAGS_RELEASELTO}")

set(CMAKE_CXX_FLAGS "-g3 -O3 -DNDEBUG -fuse-ld=gold -flto -Wall -Werror -Wunknown-pragmas -Wextra -Wwrite-strings -rdynamic -std=c++1z")

include_directories(src)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS program_options)

add_executable(
    options
    src/lines.cpp
    src/options.cpp
)
target_link_libraries(options ${Boost_LIBRARIES})
