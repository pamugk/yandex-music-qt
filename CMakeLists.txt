cmake_minimum_required(VERSION 3.5)

project(yandex-music-qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Network NetworkAuth WebEngineWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Network NetworkAuth WebEngineWidgets)

set(TS_FILES yandex-music-qt_ru_RU.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        resources.qrc

        components/albumcard.h components/albumcard.cpp components/albumcard.ui
        components/artistcard.h components/artistcard.cpp components/artistcard.ui
        components/playlistcard.h components/playlistcard.cpp components/playlistcard.ui
        components/podcastcard.h components/podcastcard.cpp components/podcastcard.ui

        pages/searchpage.h pages/searchpage.cpp pages/searchpage.ui

        api/yandexmusic.h api/yandexmusic.cpp

        api/domain/album.h api/domain/album.cpp
        api/domain/artist.h api/domain/artist.cpp
        api/domain/entity.h
        api/domain/label.h
        api/domain/playlist.h api/domain/playlist.cpp
        api/domain/podcast.h api/domain/podcast.cpp
        api/domain/video.h api/domain/video.cpp
        api/domain/user.h api/domain/user.cpp

        api/searchcategory.h api/search.h
        api/searchsuggestions.h

        api/utils/json_serialization.h api/utils/json_serialization.cpp
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(yandex-music-qt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET yandex-music-qt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(yandex-music-qt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(yandex-music-qt
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(yandex-music-qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::NetworkAuth Qt${QT_VERSION_MAJOR}::WebEngineWidgets)

set_target_properties(yandex-music-qt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(yandex-music-qt)
endif()
