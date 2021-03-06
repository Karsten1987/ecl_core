##############################################################################
# Cmake
##############################################################################

cmake_minimum_required(VERSION 3.5)
project(ecl_utilities)

##############################################################################
# Find Packages
##############################################################################

find_package(ament_cmake_ros REQUIRED)
find_package(ecl_build REQUIRED)
find_package(ecl_concepts REQUIRED)
find_package(ecl_mpl REQUIRED)

##############################################################################
# Project Configuration
##############################################################################

ament_package_xml()
ecl_enable_cxx14_compiler()
ecl_enable_cxx_warnings()

##############################################################################
# Header Library Targets
##############################################################################

add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(
  ${PROJECT_NAME}
  INTERFACE
    ecl_concepts::ecl_concepts
    ecl_mpl::ecl_mpl
)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

##############################################################################
# Sources
##############################################################################

add_subdirectory(include)
add_subdirectory(src)

##############################################################################
# Exports
##############################################################################

ament_export_interfaces(HAS_LIBRARY_TARGET ${PROJECT_NAME})
ament_export_dependencies(
    ecl_concepts
    ecl_mpl
)
ament_package()
