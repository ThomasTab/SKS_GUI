cmake_minimum_required(VERSION 3.1.0)

project(SKS_GUI VERSION 0.2.0 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "D:/Qt/5.15.0/msvc2019_64/lib/cmake")
set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/ui")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core Widgets SerialPort REQUIRED)

# Add libraries
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(SKS_GUI
    "${PROJECT_SOURCE_DIR}/apps/main.cpp"
    "${PROJECT_SOURCE_DIR}/ui/serialKeyboardServer.ui"
    "${PROJECT_SOURCE_DIR}/ui/serialKeyboardServer.qrc"
    "${PROJECT_SOURCE_DIR}/src/console.cpp"
    "${PROJECT_SOURCE_DIR}/src/serialPannel.cpp"
    "${PROJECT_SOURCE_DIR}/src/virtualKey.cpp"
    "${PROJECT_SOURCE_DIR}/src/serialKeyboardServer.cpp"
    "${PROJECT_SOURCE_DIR}/include/SKS_GUI/console.h"
    "${PROJECT_SOURCE_DIR}/include/SKS_GUI/serialPannel.h"
    "${PROJECT_SOURCE_DIR}/include/SKS_GUI/virtualKey.h"
    "${PROJECT_SOURCE_DIR}/include/SKS_GUI/serialKeyboardServer.h"
)

target_link_libraries(SKS_GUI Qt5::Core Qt5::Widgets Qt5::SerialPort)