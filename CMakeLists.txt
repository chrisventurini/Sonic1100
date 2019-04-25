# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (CMakeProject1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Quick WebEngine REQUIRED)

include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5WebEngine_INCLUDE_DIRS})

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "./Source/main.cpp" "./Resources/qml.qrc")

# TODO: Add tests and install targets if needed.
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick Qt5::WebEngine)
