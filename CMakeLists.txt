cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install" CACHE PATH "Force root install directory" FORCE)

project(zerox_memory_bridge)

set(CMAKE_CXX_STANDARD 20 REQUIRED)
set(PROJECT_NAME zerox_memory_bridge)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if(WIN32)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glm)
elseif(UNIX)
    find_package(glm 1.0 REQUIRED)
endif()

target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} INTERFACE 
    $<BUILD_INTERFACE:glm::glm>
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(CONFIG_INSTALL_DIR "${CMAKE_INSTALL_DATADIR}/cmake/${PROJECT_NAME}")

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "zerox_memory_bridgeConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CONFIG_INSTALL_DIR}"
)

install(DIRECTORY include/ DESTINATION include)

if(WIN32)
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/glm/glm/" DESTINATION include/glm)
elseif(UNIX)
    get_target_property(GLM_INC glm::glm INTERFACE_INCLUDE_DIRECTORIES)
    if(GLM_INC)
        install(DIRECTORY "${GLM_INC}/glm/" DESTINATION include/glm)
    endif()
endif()

# 5. Export and Install Target Specifications (Typo Fixed)
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets)

install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION "${CONFIG_INSTALL_DIR}"
)

# Install configuration files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION "${CONFIG_INSTALL_DIR}"
)