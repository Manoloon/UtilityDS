cmake_minimum_required(VERSION 3.25.0)
project(UtilityDS VERSION 1.0.0 LANGUAGES C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(UtilityDS STATIC 
        src/dynamicArray.c 
        src/queue.c)
add_library(UtilityDS::UtilityDS ALIAS UtilityDS)

target_include_directories(UtilityDS PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_options(UtilityDS PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

# Installation directories
set(UtilityDS_INSTALL_CMAKEDIR
    ${CMAKE_INSTALL_LIBDIR}/cmake/UtilityDS
)
# Install library
install(
    TARGETS UtilityDS
    EXPORT UtilityDSTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
# Install public headers
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
# Export targets
install(
    EXPORT UtilityDSTargets
    FILE UtilityDSTargets.cmake
    NAMESPACE UtilityDS::
    DESTINATION ${UtilityDS_INSTALL_CMAKEDIR}
)
configure_package_config_file(
    cmake/UtilityDSConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/UtilityDSConfig.cmake
    INSTALL_DESTINATION ${UtilityDS_INSTALL_CMAKEDIR}
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/UtilityDSConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
# Install package configuration files
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/UtilityDSConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/UtilityDSConfigVersion.cmake
    DESTINATION ${UtilityDS_INSTALL_CMAKEDIR}
)