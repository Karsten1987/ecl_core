##############################################################################
# Cmake
##############################################################################

cmake_minimum_required(VERSION 3.5)
project(ecl_ipc)

##############################################################################
# Find Packages
##############################################################################

find_package(ament_cmake_ros REQUIRED)
find_package(ecl_build REQUIRED)
find_package(ecl_config REQUIRED)
find_package(ecl_errors REQUIRED)
find_package(ecl_time_lite REQUIRED)
find_package(ecl_exceptions REQUIRED)
find_package(ecl_threads REQUIRED)
find_package(ecl_time REQUIRED)

##############################################################################
# Project Configuration
##############################################################################

ament_package_xml()
ecl_enable_cxx14_compiler()
ecl_enable_cxx_warnings()
ecl_detect_threads()

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
    ecl_config
    ecl_errors
    ecl_exceptions
    ecl_threads
    ecl_time_lite
    ecl_time
)
ament_package()
