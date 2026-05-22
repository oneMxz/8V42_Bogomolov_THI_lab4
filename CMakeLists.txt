cmake_minimum_required(VERSION 3.10)
project(NewYearGift VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==================== БИБЛИОТЕКА (DLL) ====================

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/NewYearGiftLib/include)

set(LIB_SOURCES
    NewYearGiftLib/src/AbstractSweet.cpp
    NewYearGiftLib/src/Candy.cpp
    NewYearGiftLib/src/ChocolateCandy.cpp
    NewYearGiftLib/src/CaramelCandy.cpp
    NewYearGiftLib/src/Lollipop.cpp
    NewYearGiftLib/src/Marshmallow.cpp
    NewYearGiftLib/src/NewYearGift.cpp
    NewYearGiftLib/src/ChocolateCandyFactory.cpp
    NewYearGiftLib/src/CaramelCandyFactory.cpp
    NewYearGiftLib/src/LollipopFactory.cpp
    NewYearGiftLib/src/MarshmallowFactory.cpp
    NewYearGiftLib/src/GiftService.cpp
    NewYearGiftLib/src/ConsoleLogger.cpp
    NewYearGiftLib/src/FileLogger.cpp
    NewYearGiftLib/src/ConsoleLoggerFactory.cpp
    NewYearGiftLib/src/FileLoggerFactory.cpp
)

set(LIB_HEADERS
    ${INCLUDE_DIR}/Export.h
    ${INCLUDE_DIR}/AbstractSweet.h
    ${INCLUDE_DIR}/Candy.h
    ${INCLUDE_DIR}/ChocolateCandy.h
    ${INCLUDE_DIR}/CaramelCandy.h
    ${INCLUDE_DIR}/Lollipop.h
    ${INCLUDE_DIR}/Marshmallow.h
    ${INCLUDE_DIR}/NewYearGift.h
    ${INCLUDE_DIR}/SweetFactory.h
    ${INCLUDE_DIR}/ChocolateCandyFactory.h
    ${INCLUDE_DIR}/CaramelCandyFactory.h
    ${INCLUDE_DIR}/LollipopFactory.h
    ${INCLUDE_DIR}/MarshmallowFactory.h
    ${INCLUDE_DIR}/GiftService.h
    ${INCLUDE_DIR}/ILogger.h
    ${INCLUDE_DIR}/ConsoleLogger.h
    ${INCLUDE_DIR}/FileLogger.h
    ${INCLUDE_DIR}/LoggerFactory.h
    ${INCLUDE_DIR}/ConsoleLoggerFactory.h
    ${INCLUDE_DIR}/FileLoggerFactory.h
)

add_library(NewYearGiftLib SHARED ${LIB_SOURCES} ${LIB_HEADERS})
target_compile_definitions(NewYearGiftLib PRIVATE NEWYEARGIFTLIB_EXPORTS)
target_include_directories(NewYearGiftLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/NewYearGiftLib/include)

# ==================== ПРИЛОЖЕНИЕ (EXE) ====================
add_executable(NewYearGiftApp
    NewYearGiftApp/main.cpp
    NewYearGiftApp/ConsoleUI.cpp
)

target_link_libraries(NewYearGiftApp PRIVATE NewYearGiftLib)
target_include_directories(NewYearGiftApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/NewYearGiftLib/include)

if(WIN32)
    add_custom_command(TARGET NewYearGiftApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:NewYearGiftLib>
            $<TARGET_FILE_DIR:NewYearGiftApp>
        COMMENT "Копирование DLL в директорию приложения..."
    )
endif()

message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "DLL: NewYearGiftLib")
message(STATUS "EXE: NewYearGiftApp")