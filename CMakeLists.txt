cmake_minimum_required(VERSION 3.7)
project(MaybSFML)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Source/Application.cpp
        Source/Application.hpp Source/Config.hpp
        Source/Main.cpp
        Source/Utils/FPSCounter.cpp
        Source/Utils/FPSCounter.hpp
        Source/Rendering/RenderManager.cpp
        Source/Rendering/RenderManager.hpp
        Source/Player/Player.cpp
        Source/Player/Player.hpp
        Source/Entity.cpp Source/Entity.hpp
        Source/Maths/Vector2.cpp
        Source/Maths/Vector2.hpp
        Source/Maths/Collider.cpp
        Source/Maths/Collider.hpp
        Source/Scenes/Scene.hpp
        Source/Scenes/MenuScene.cpp
        Source/Scenes/MenuScene.hpp
        )
add_executable(MaybSFML ${SOURCE_FILES})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

target_link_libraries(MaybSFML -lsfml-graphics -lsfml-window -lsfml-system)