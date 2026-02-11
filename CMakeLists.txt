cmake_minimum_required(VERSION 3.31)
project(raylibExp C)

set(CMAKE_C_STANDARD 23)
# 2. Define where raylib is located
set(RAYLIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external/raylib")
# 3. Tell the compiler where the header files (.h) are
include_directories(${RAYLIB_PATH}/include)
# 4. Tell the linker where the library files (.lib / .a) are
link_directories(${RAYLIB_PATH}/lib)
# 5. Create your executable
add_executable(raylibExp main.c)
# 6. Link raylib and Windows system dependencies
# Note: On Windows, raylib needs winmm, gdi32, and opengl32
target_link_libraries(${PROJECT_NAME} raylib winmm gdi32 opengl32)
