set (CMAKE_COLOR_DIAGNOSTICS ON)

include (FetchContent)

set (FMT_VERSION 10.1.1)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG ${FMT_VERSION}
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)

set (FMT_TEST OFF)

FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
    notcurses
    GIT_REPOSITORY https://github.com/dankamongmen/notcurses
    GIT_TAG master
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)

include_directories (${notcurses_SOURCE_DIR}/include)

set (BUILD_TESTING OFF)
set (USE_PANDOC OFF)
set (BUILD_EXECUTABLES OFF)
set (USE_POC OFF)

FetchContent_MakeAvailable(notcurses)

file(GLOB CPP_SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${CPP_SOURCES})

target_link_libraries(${PROJECT_NAME} fmt notcurses++ notcurses-core)
