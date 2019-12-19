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
        src/gameflow/menuflow.cpp src/gameflow/menuflow.h src/entities/ui/hud.cpp src/entities/ui/hud.h)


#target_link_libraries(${PROJECT_NAME_VALUE} , reactphysics3d)

if (WIN32)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lmingw32
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lSDL2_mixer
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
            -lSDL2_mixer
            -lGL
            -lGLU
    )
endif ()