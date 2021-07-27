cmake_minimum_required(VERSION 3.17)
project(inflammable)

set(CMAKE_CXX_STANDARD 17)

add_executable(inflammable
        main.cpp
        src/App.cpp
        src/GameObjects/Player/Player.cpp
        src/GameObjects/Level/Level.h
        src/GameObjects/GameObject.h
        src/GameObjects/PhysObject.cpp
        src/GameObjects/Wall/Wall.cpp
        src/GameObjects/Wall/Wall.h
        src/GameObjects/GameObject.cpp)

# sfml include magic

include_directories(src /usr/include c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(inflammable ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()