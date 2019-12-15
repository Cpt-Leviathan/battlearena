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
        src/gameflow/gameflow.cpp src/gameflow/gameflow.h src/managers/tankManager.cpp src/managers/tankManager.h src/managers/bulletManager.cpp src/managers/bulletManager.h src/entities/Tank.cpp src/entities/Tank.h src/entities/Bullet.cpp src/entities/Bullet.h src/utils/includes.h src/gameflow/setup.cpp src/gameflow/setup.h src/entities/terrain.cpp src/entities/terrain.h src/entities/wall.cpp src/entities/wall.h src/managers/terrainManager.cpp src/managers/terrainManager.h src/managers/manager.cpp src/managers/manager.h src/entities/Direction.h src/entities/Camera.cpp src/entities/Camera.h src/managers/CameraManager.cpp src/managers/CameraManager.h src/entities/IDestructive.cpp src/entities/IDestructive.h)

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