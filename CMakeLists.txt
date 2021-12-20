cmake_minimum_required(VERSION 3.7)
project(MaybSFML)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 3.0 COMPONENTS system window graphics REQUIRED)

set(ALL_FILES
    # Source Root
    Source/Config.hpp
    Source/Main.cpp
    Source/Application.cpp
    Source/Application.hpp
    Source/TextureCache.cpp
    Source/TextureCache.hpp
    # Utils
    Source/Utils/FPSCounter.cpp
    Source/Utils/FPSCounter.hpp
    Source/Utils/SpriteBuilder.cpp
    Source/Utils/SpriteBuilder.hpp
    Source/Utils/GameSave.cpp
    Source/Utils/GameSave.hpp
    Source/Utils/Stash.cpp
    Source/Utils/Stash.hpp
    Source/Utils/ResourceManager.hpp
    Source/Utils/ResourceManager.cpp
    # Rendering
    Source/Rendering/RenderManager.cpp
    Source/Rendering/RenderManager.hpp
    Source/Rendering/Renderable.hpp
    Source/Rendering/Renderable.cpp
    # Player
    Source/Player/Player.cpp
    Source/Player/Player.hpp
    # Entity
    Source/Entity.cpp
    Source/Entity.hpp
    # Maths
    Source/Maths/Collider.cpp
    Source/Maths/Collider.hpp
    # Scenes
    Source/Scenes/Scene.hpp
    Source/Scenes/MenuScene.cpp
    Source/Scenes/MenuScene.hpp
    Source/Scenes/GameScene.cpp
    Source/Scenes/GameScene.hpp
    Source/Scenes/SplashScreen.cpp
    Source/Scenes/SplashScreen.hpp
    Source/Scenes/PopUpMenu.cpp
    Source/Scenes/PopUpMenu.hpp
    # World
    Source/World/World.cpp
    Source/World/World.hpp
    Source/World/WorldLoader.cpp
    Source/World/WorldLoader.hpp
    Source/World/Objects/Block.cpp
    Source/World/Objects/Block.hpp
    Source/World/Objects/GameObject.cpp
    Source/World/Objects/GameObject.hpp
    # States
    Source/States/Serializable.hpp
    # World Maker
    Source/WorldMaker/WorldMaker.cpp
    Source/WorldMaker/WorldMaker.hpp
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
)

add_executable(MaybSFML ${ALL_FILES})

if (DEVELOPER_MODE)
    # Clang Format
    add_custom_target(
        ClangFormat
        DEPENDS ${ALL_FILES}
        COMMAND clang-format -i ${ALL_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Formatting files using clang-format..."
        VERBATIM
    )
    add_dependencies(MaybSFML ClangFormat)
    # Useful for external tools - ClangTidy, etc.
    set_target_properties(MaybSFML PROPERTIES EXPORT_COMPILE_COMMANDS TRUE)
    # My mess which I don't really want to fix
    target_link_directories(MaybSFML PRIVATE /usr/local/lib)
    target_include_directories(MaybSFML PRIVATE /usr/local/include)
endif()

target_include_directories(MaybSFML PUBLIC Source)
target_link_libraries(MaybSFML -lsfml-graphics -lsfml-window -lsfml-system)
