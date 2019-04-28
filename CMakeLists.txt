# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (Sonic1100)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core WebEngine WebEngineCore WebChannel WebEngineWidgets REQUIRED)

include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5WebEngine_INCLUDE_DIRS} ${Qt5WebEngineWidgets_INCLUDE_DIRS} ${Qt5WebEngineCore_INCLUDE_DIRS})

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "./Source/main.cpp" "./Source/WebManager.h" "./Source/WebManager.cpp" "./Resources/qml.qrc")

# TODO: Add tests and install targets if needed.
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::WebEngine Qt5::WebChannel Qt5::WebEngineWidgets Qt5::WebEngineCore)
