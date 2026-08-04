cmake_minimum_required(VERSION 3.25)

# Include CPM to handle Geode SDK fetching automatically
include(FetchContent)
FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG main
)
FetchContent_MakeAvailable(Geode)

project(gdps_demonlist VERSION 1.0.0 LANGUAGES CXX)

add_geode_mod(
    gdps_demonlist
    "1.0.0"
    src/main.cpp
)
