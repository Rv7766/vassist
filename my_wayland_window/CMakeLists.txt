cmake_minimum_required(VERSION 3.12)  # Specify minimum CMake version
project(MyWaylandWindow CXX)           # Define the project name and language

# Find Wayland client library
find_package(Wayland REQUIRED)

# Generate xdg-shell protocol headers and sources (xdg_shell is used for windows)
# The xdg-shell protocol definition is located in /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml
execute_process(COMMAND wayland-scanner client-header < /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml > ${CMAKE_BINARY_DIR}/xdg-shell-client-protocol.h)
execute_process(COMMAND wayland-scanner private-code < /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml > ${CMAKE_BINARY_DIR}/xdg-shell-protocol.c)

# Add the generated files to your source files
add_executable(my_wayland_window main.cpp ${CMAKE_BINARY_DIR}/xdg-shell-protocol.c)

# Link against Wayland client and other required libraries
target_link_libraries(my_wayland_window PRIVATE Wayland::Client rt)  # Link against Wayland client library and real-time library


find_package(PkgConfig)
pkg_check_modules(WAYLAND_CLIENT REQUIRED wayland-client)
target_link_libraries(my_wayland_window PRIVATE ${WAYLAND_CLIENT_LIBRARIES})
