cmake_minimum_required(VERSION 3.31)
project(AvaliacaoDaPuc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(glm CONFIG REQUIRED) ## GLM
find_package(fmt CONFIG REQUIRED)


include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)



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
)

target_link_libraries(AvaliacaoDaPuc PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        glm::glm
        glm::glm-header-only
        fmt::fmt
)

# Adicione após o seu add_executable()
if(WIN32)
    set(DEBUG_SUFFIX)
    if(MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif()
    
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if(NOT EXISTS "${QT_INSTALL_PATH}")
        set(QT_INSTALL_PATH "C:/Qt/6.9.0/msvc2022_64")
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
endif()
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    # Usar QT_INSTALL_PATH passado ou inferir
    if (QT_INSTALL_PATH)
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}")
    else ()
        set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    endif ()
    message("Using QT_INSTALL_PATH: ${QT_INSTALL_PATH}")  # Depuração
    # Verificar e copiar DLLs
    if (EXISTS "${QT_INSTALL_PATH}/bin/Qt6Cored.dll")
        foreach (QT_LIB Core Gui Widgets)
            add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
        endforeach (QT_LIB)
    else ()
        message(FATAL_ERROR "Qt DLLs not found in ${QT_INSTALL_PATH}/bin. Check QT installation at ${QT_INSTALL_PATH}.")
    endif ()
    # Verificar e copiar plugin de plataforma
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    else ()
        message(FATAL_ERROR "Qt platform plugin not found in ${QT_INSTALL_PATH}/plugins/platforms. Check QT installation at ${QT_INSTALL_PATH}.")
    endif ()
endif ()