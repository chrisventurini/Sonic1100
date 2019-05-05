# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (Sonic1100)
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MSVCIDE_RUN_PATH "./Native/3rdParty/Python/3.7.3/libs/amd64")

add_subdirectory("Web")

find_package(Qt5 COMPONENTS Core WebEngine WebEngineCore WebChannel WebEngineWidgets REQUIRED)

include_directories(
	${Qt5Core_INCLUDE_DIRS} 
	${Qt5WebEngine_INCLUDE_DIRS} 
	${Qt5WebEngineWidgets_INCLUDE_DIRS} 
	${Qt5WebEngineCore_INCLUDE_DIRS}
	"./Native/3rdParty/Python/3.7.3/include/"
)

link_directories("./Native/3rdParty/Python/3.7.3/libs/amd64")
 
file (GLOB_RECURSE NATIVE_SOURCE "./Native/Source/*.*")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${NATIVE_SOURCE} "./Native/Resources/resources.qrc")

# TODO: Add tests and install targets if needed.
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::WebEngine Qt5::WebChannel Qt5::WebEngineWidgets Qt5::WebEngineCore)

ADD_DEPENDENCIES(${PROJECT_NAME} GENERATE_WEB_UI)