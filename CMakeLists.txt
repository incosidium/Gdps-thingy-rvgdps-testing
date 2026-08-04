cmake_minimum_required(VERSION 3.25)

include($ENV{GEODE_SDK}/cmake/link.cmake)

project(gdps_demonlist VERSION 1.0.0 LANGUAGES CXX)

find_package(Geode REQUIRED)

add_geode_mod(
    gdps_demonlist
    "1.0.0"
    src/main.cpp
)
