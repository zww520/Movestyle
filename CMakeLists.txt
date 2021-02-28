cmake_minimum_required(VERSION 3.17)
project(Movestyle)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.13.1\\5.13.1\\mingw73_64\\")


include_directories(
        C:\\Users\\18378\\Downloads\\ffmpeg-n4.3.1-20-g8a2acdc6da-win64-gpl-shared-4.3\\include
)

link_directories(
        C:\\Users\\18378\\Downloads\\ffmpeg-n4.3.1-20-g8a2acdc6da-win64-gpl-shared-4.3\\lib
)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(
        Movestyle
        main.cpp
        timer.cpp
        timer.h
        data.cpp
        data.h
        single_data_queue.cpp
        single_data_queue.h
        ffmpeger.cpp
        ffmpeger.h
        resolver.cpp
        resolver.h
        video_resolver.cpp
        video_resolver.h
        controller.cpp
        controller.h
        wallpaper_window.cpp
        wallpaper_window.h
        utils.cpp utils.h
        error.h
        mainwindow.cpp
        mainwindow.h
        error.cpp global_string.h)

target_link_libraries(
        Movestyle
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        avcodec
        avdevice
        avformat
        avfilter
        swscale
        avutil
)