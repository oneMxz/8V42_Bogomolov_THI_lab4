cmake_minimum_required(VERSION 3.10)
project(NewYearGift VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==================== БИБЛИОТЕКА (DLL) ====================
set(LIB_SOURCES
    NewYearGiftLib/AbstractSweet.cpp
    NewYearGiftLib/Candy.cpp
    NewYearGiftLib/ChocolateCandy.cpp
    NewYearGiftLib/CaramelCandy.cpp
    NewYearGiftLib/Lollipop.cpp
    NewYearGiftLib/Marshmallow.cpp
    NewYearGiftLib/NewYearGift.cpp
    NewYearGiftLib/ChocolateCandyFactory.cpp
    NewYearGiftLib/CaramelCandyFactory.cpp
    NewYearGiftLib/LollipopFactory.cpp
    NewYearGiftLib/MarshmallowFactory.cpp
    NewYearGiftLib/GiftService.cpp
    NewYearGiftLib/ConsoleLogger.cpp
    NewYearGiftLib/FileLogger.cpp
    NewYearGiftLib/ConsoleLoggerFactory.cpp
    NewYearGiftLib/FileLoggerFactory.cpp
)

set(LIB_HEADERS
    NewYearGiftLib/Export.h
    NewYearGiftLib/AbstractSweet.h
    NewYearGiftLib/Candy.h
    NewYearGiftLib/ChocolateCandy.h
    NewYearGiftLib/CaramelCandy.h
    NewYearGiftLib/Lollipop.h
    NewYearGiftLib/Marshmallow.h
    NewYearGiftLib/NewYearGift.h
    NewYearGiftLib/SweetFactory.h
    NewYearGiftLib/ChocolateCandyFactory.h
    NewYearGiftLib/CaramelCandyFactory.h
    NewYearGiftLib/LollipopFactory.h
    NewYearGiftLib/MarshmallowFactory.h
    NewYearGiftLib/GiftService.h
    NewYearGiftLib/ILogger.h
    NewYearGiftLib/ConsoleLogger.h
    NewYearGiftLib/FileLogger.h
    NewYearGiftLib/LoggerFactory.h
    NewYearGiftLib/ConsoleLoggerFactory.h
    NewYearGiftLib/FileLoggerFactory.h
)

add_library(NewYearGiftLib SHARED ${LIB_SOURCES} ${LIB_HEADERS})
target_compile_definitions(NewYearGiftLib PRIVATE NEWYEARGIFTLIB_EXPORTS)
target_include_directories(NewYearGiftLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/NewYearGiftLib)

# ==================== ПРИЛОЖЕНИЕ (EXE) ====================
add_executable(NewYearGiftApp
    NewYearGiftApp/main.cpp
    NewYearGiftApp/ConsoleUI.cpp
)

target_link_libraries(NewYearGiftApp PRIVATE NewYearGiftLib)
target_include_directories(NewYearGiftApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/NewYearGiftLib)

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