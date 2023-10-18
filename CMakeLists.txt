cmake_minimum_required(VERSION 3.23)
project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)

if(APPLE)
    set(OpenGlLinkers "-framework OpenGL" "-lglfw" "-lGLEW")
    include_directories(/opt/homebrew/include)
    link_directories(/opt/homebrew/lib)
else()
    set(OpenGlLinkers -lGL -lglfw -lGLEW)
endif()

add_executable(OpenGLProject main.cpp
        src/Application.cpp
        include/Application.h
        src/Window.cpp
        include/Window.h
        src/Renderer.cpp
        include/Renderer.h
        src/Shader.cpp
        include/Shader.h
        src/FileParser.cpp
        include/FileParser.h
        src/VertexBuffer.cpp
        include/VertexBuffer.h
        src/GObject.cpp
        include/GObject.h
        include/Debug.h
        include/AppStructs.h
        src/GObjectFactory.cpp
        include/GObjectFactory.h
        src/Texture.cpp
        include/Texture.h
        include/vendor/stb_image.h
        include/vendor/stb_image.cpp
)
target_link_libraries(OpenGLProject ${OpenGlLinkers})
