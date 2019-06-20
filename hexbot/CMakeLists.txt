cmake_minimum_required(VERSION 3.1.0)

project(hexbot)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Widgets Network Gui REQUIRED)


set(hexbot_SRCS
    mainwindow.ui
    mainwindow.cpp
    main.cpp
)

add_executable(hexbot ${hexbot_SRCS})
target_link_libraries(hexbot
	Qt5::Widgets
	Qt5::Gui
	Qt5::Network)
