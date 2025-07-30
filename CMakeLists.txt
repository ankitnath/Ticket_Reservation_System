cmake_minimum_required(VERSION 3.10)
project(TicketReservation)

set(CMAKE_CXX_STANDARD 17)

# Core reservation logic library
add_library(reservation_system
    reservation_system.cpp
    reservation_system.hpp
)

# CLI executable (no GUI code)
add_executable(ticket_cli main.cpp)
target_link_libraries(ticket_cli reservation_system)

# ImGui source files
file(GLOB IMGUI_SRC
    imgui/*.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

# GUI executable (separate main for GUI)
add_executable(ticket_gui
    gui_main.cpp  # Separate GUI entry point
    gui.cpp       # GUI implementation
    ${IMGUI_SRC}
)

# Find required packages for GUI
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(GLEW REQUIRED)

# Include directories for GUI
target_include_directories(ticket_gui PRIVATE
    imgui
    imgui/backends
    ${GLFW_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
)

# Link libraries for GUI
target_link_libraries(ticket_gui
    reservation_system
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
    OpenGL::GL
    GL
    pthread
    dl
)

# Google Test setup (unit tests)
enable_testing()
find_package(GTest REQUIRED)

add_executable(unit_tests test/test_reserve_system.cpp)
target_link_libraries(unit_tests
    reservation_system
    GTest::gtest_main
    pthread
)

include(GoogleTest)
gtest_discover_tests(unit_tests)