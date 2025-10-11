cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ShopSystem VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Compiler-specific options
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Core
    ${CMAKE_SOURCE_DIR}/Entities
    ${CMAKE_SOURCE_DIR}/Manager
    ${CMAKE_SOURCE_DIR}/UI
)

# Source files for Core
set(CORE_SOURCES
    Core/ShopSystem.cpp
    Core/Util.cpp
)

# Source files for Entities
set(ENTITIES_SOURCES
    Entities/Admin.cpp
    Entities/Cart.cpp
    Entities/Customer.cpp
    Entities/Order.cpp
    Entities/Product.cpp
)

# Source files for Manager
set(MANAGER_SOURCES
    Manager/OrderManager.cpp
    Manager/ProductManager.cpp
    Manager/UserManager.cpp
)

# Source files for UI
set(UI_SOURCES
    UI/AdminUIHandler.cpp
    UI/CustomerUIHandler.cpp
    UI/MenuSystem.cpp
)

# Header files for Core
set(CORE_HEADERS
    Core/Exception.hpp
    Core/ShopSystem.hpp
    Core/Util.hpp
)

# Header files for Entities
set(ENTITIES_HEADERS
    Entities/Admin.hpp
    Entities/Cart.hpp
    Entities/Customer.hpp
    Entities/Order.hpp
    Entities/Product.hpp
    Entities/User.hpp
)

# Header files for Manager
set(MANAGER_HEADERS
    Manager/OrderManager.hpp
    Manager/ProductManager.hpp
    Manager/UserManager.hpp
)

# Header files for UI
set(UI_HEADERS
    UI/AdminUIHandler.hpp
    UI/CustomerUIHandler.hpp
    UI/MenuSystem.hpp
    UI/OrderUI.hpp
    UI/ProductUI.hpp
)

# Combine all sources
set(ALL_SOURCES
    ${CORE_SOURCES}
    ${ENTITIES_SOURCES}
    ${MANAGER_SOURCES}
    ${UI_SOURCES}
    main.cpp
)

# Combine all headers
set(ALL_HEADERS
    ${CORE_HEADERS}
    ${ENTITIES_HEADERS}
    ${MANAGER_HEADERS}
    ${UI_HEADERS}
)

# Create the executable
add_executable(${PROJECT_NAME} ${ALL_SOURCES} ${ALL_HEADERS})

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Create build directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Optional: Create a static library for the project (excluding main.cpp)
set(LIB_SOURCES
    ${CORE_SOURCES}
    ${ENTITIES_SOURCES}
    ${MANAGER_SOURCES}
    ${UI_SOURCES}
)

add_library(ShopSystemLib STATIC ${LIB_SOURCES} ${ALL_HEADERS})

# Link the library to the main executable
target_link_libraries(${PROJECT_NAME} ShopSystemLib)

# Print build information
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Source directory: ${CMAKE_SOURCE_DIR}")
message(STATUS "Binary directory: ${CMAKE_BINARY_DIR}")

# Optional: Add install targets
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# Optional: Add custom target to clean build files
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMENT "Cleaning all build files"
)