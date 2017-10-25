cmake_minimum_required(VERSION 3.7)
project(MaybSFML)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Source/Config.hpp
        Source/Main.cpp
        Source/Application.cpp
        Source/Application.hpp
        Source/Utils/FPSCounter.cpp
        Source/Utils/FPSCounter.hpp
        Source/Rendering/RenderManager.cpp
        Source/Rendering/RenderManager.hpp
        Source/Rendering/Renderable.hpp
        Source/Rendering/Renderable.cpp
        Source/Player/Player.cpp
        Source/Player/Player.hpp
        Source/Entity.cpp
        Source/Entity.hpp
        Source/Maths/Collider.cpp
        Source/Maths/Collider.hpp
        Source/Scenes/Scene.hpp
        Source/Scenes/MenuScene.cpp
        Source/Scenes/MenuScene.hpp
        Source/Scenes/GameScene.cpp
        Source/Scenes/GameScene.hpp
        Source/Scenes/SplashScreen.cpp
        Source/Scenes/SplashScreen.hpp
        Source/World/World.cpp
        Source/World/World.hpp
        Source/World/WorldLoader.cpp
        Source/World/WorldLoader.hpp
        Source/World/Objects/Block.cpp
        Source/World/Objects/Block.hpp
        Source/World/Objects/GameObject.cpp
        Source/World/Objects/GameObject.hpp
        Source/Utils/SpriteBuilder.cpp Source/Utils/SpriteBuilder.hpp)
add_executable(MaybSFML ${SOURCE_FILES})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

target_link_libraries(MaybSFML -lsfml-graphics -lsfml-window -lsfml-system)