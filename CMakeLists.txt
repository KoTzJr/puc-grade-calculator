cmake_minimum_required(VERSION 3.31)
project(AvaliacaoDaPuc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-g -O0)

# -------------------------
# Bibliotecas externas
# -------------------------
find_package(fmt CONFIG REQUIRED) ## Fmt
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED) ## QT
find_package(nlohmann_json CONFIG REQUIRED) ## JSON

# -------------------------
# Includes
# -------------------------
include_directories(${CMAKE_SOURCE_DIR}/include)

# Caminho de UI
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src)

# -------------------------
# Executável
# -------------------------
add_executable(AvaliacaoDaPuc
        src/main.cpp
        _windows_.ui
        src/_windows_.cpp
        include/_windows_.h
        src/system_nota.cpp
        include/system_nota.h
        src/_ui_.cpp
        include/_ui_.h
        resources.qrc
        src/ListDataItens.cpp
        include/ListDataItens.h
        src/FileManger.cpp
        include/FileManger.h
        src/PreferenceSystem.cpp
        include/PreferenceSystem.h
        option.ui
        include/Info_config.h
        src/idioma_ui.cpp
        include/idioma_ui.h
        src/global_acess.cpp
        include/global_acess.h
        src/info_window.cpp
        include/info_window.h
        info_window.ui
        src/InfoSystemDebug.cpp
        include/InfoSystemDebug.h
)

# -------------------------
# Linkagem
# -------------------------
target_link_libraries(AvaliacaoDaPuc PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        fmt::fmt
        nlohmann_json::nlohmann_json
)
# -------------------------
# Pós-build (Qt)
# -------------------------
if(WIN32)
    set(DEBUG_SUFFIX)
    if(MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif()

    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if(NOT EXISTS "${QT_INSTALL_PATH}")
        set(QT_INSTALL_PATH "C:\\Qt\\6.9.1\\msvc2022_64")
    endif()

    if(EXISTS "${QT_INSTALL_PATH}/bin")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_INSTALL_PATH}/bin/Qt6Core${DEBUG_SUFFIX}.dll"
                "${QT_INSTALL_PATH}/bin/Qt6Gui${DEBUG_SUFFIX}.dll"
                "${QT_INSTALL_PATH}/bin/Qt6Widgets${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/"
        )
    endif()

    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif()
endif()
