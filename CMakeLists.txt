cmake_minimum_required(VERSION 3.7)
project(MaybSFML)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 3.0 COMPONENTS system window graphics REQUIRED)
include_directories(/usr/local/include)

set(SOURCE_FILES
        Source/Config.hpp
        Source/Main.cpp
        Source/Application.cpp
        Source/Application.hpp
        Source/Utils/FPSCounter.cpp
        Source/Utils/FPSCounter.hpp
        Source/Utils/SpriteBuilder.cpp
        Source/Utils/SpriteBuilder.hpp
        Source/Utils/GameSave.cpp
        Source/Utils/GameSave.hpp
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
        Source/Scenes/PopUpMenu.cpp
        Source/Scenes/PopUpMenu.hpp
        Source/World/World.cpp
        Source/World/World.hpp
        Source/World/WorldLoader.cpp
        Source/World/WorldLoader.hpp
        Source/World/Objects/Block.cpp
        Source/World/Objects/Block.hpp
        Source/World/Objects/GameObject.cpp
        Source/World/Objects/GameObject.hpp
        Source/States/Serializable.hpp
        Source/WorldMaker/WorldMaker.cpp
        Source/WorldMaker/WorldMaker.hpp
        Source/Utils/Stash.cpp
        Source/Utils/Stash.hpp
        Source/WorldMaker/Button.cpp
        Source/WorldMaker/Button.hpp
        Source/WorldMaker/States/IFunctionState.hpp
        Source/WorldMaker/States/NoFunction.cpp
        Source/WorldMaker/States/NoFunction.hpp
        Source/WorldMaker/States/FunctionManager.cpp
        Source/WorldMaker/States/FunctionManager.hpp
        Source/WorldMaker/States/PlacerFunction.cpp
        Source/WorldMaker/States/PlacerFunction.hpp
        Source/WorldMaker/States/RemovalFunction.cpp
        Source/WorldMaker/States/RemovalFunction.hpp
        Source/TextureLoader.cpp
        Source/TextureLoader.hpp
        )
add_executable(MaybSFML ${SOURCE_FILES})

target_link_directories(MaybSFML PUBLIC /usr/local/lib)
target_link_libraries(MaybSFML -lsfml-graphics -lsfml-window -lsfml-system)