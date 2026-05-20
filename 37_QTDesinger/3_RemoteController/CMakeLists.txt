cmake_minimum_required(VERSION 3.15)
project(3_RemoteController)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение автоматической сборки Qt файлов
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Путь Qt
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.5.1/5.5/mingw492_32/lib/cmake")

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(${PROJECT_NAME} main.cpp remote_UI.ui remoteContr.h)

# Привязываем библиотеки к ПРОЕКТУ, а не к UI файлу
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

# Автоматическое развертывание DLL для Windows с помощью утилиты из комплекта Qt
if (WIN32)
    # Находим путь к утилите windeployqt.exe на основе путей найденного пакета Qt5
    get_target_property(_qt_core_executable Qt5::Core LOCATION)
    get_filename_component(_qt_bin_dir "${_qt_core_executable}" DIRECTORY)
    set(WINDEPLOYQT_EXE "${_qt_bin_dir}/windeployqt.exe")

    if (EXISTS "${WINDEPLOYQT_EXE}")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND "${WINDEPLOYQT_EXE}" "$<TARGET_FILE:${PROJECT_NAME}>"
                COMMENT "Running windeployqt to copy required Qt DLLs..."
        )
    endif()
endif()
