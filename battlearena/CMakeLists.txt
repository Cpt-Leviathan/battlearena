cmake_minimum_required(VERSION 3.13)


set(
        PROJECT_NAME_VALUE
        battlearena
)

project(${PROJECT_NAME_VALUE})

file(
        GLOB_RECURSE
        source_files
        src/*
)

file(
        COPY
        assets
        DESTINATION
        ${CMAKE_BINARY_DIR}
)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME_VALUE}
        ${source_files}
        src/gameflow/gameflow.cpp src/gameflow/gameflow.h src/managers/tankManager.cpp src/managers/tankManager.h src/managers/bulletManager.cpp src/managers/bulletManager.h src/entities/tank.cpp src/entities/tank.h src/entities/bullet.cpp src/entities/bullet.h src/utils/includes.h src/gameflow/setup.cpp src/gameflow/setup.h)

#target_link_libraries(${PROJECT_NAME_VALUE} , reactphysics3d)

if (WIN32)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lmingw32
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lopengl32
            -lglu32
    )
endif ()

if (UNIX)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lGL
            -lGLU
    )
endif ()