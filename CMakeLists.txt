cmake_minimum_required(VERSION 3.16)

project(mib-generator
        VERSION 1.0
        DESCRIPTION "Simple MIB-generator"
        )

set(srcs
    mib-generator.cpp
    MibGenerator.cpp
    )
add_executable(${PROJECT_NAME} ${srcs})

find_package(json-c REQUIRED)
target_link_libraries(${PROJECT_NAME} json-c)
