INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_PI_MODULATORS pi_modulators)

FIND_PATH(
    PI_MODULATORS_INCLUDE_DIRS
    NAMES pi_modulators/api.h
    HINTS $ENV{PI_MODULATORS_DIR}/include
        ${PC_PI_MODULATORS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    PI_MODULATORS_LIBRARIES
    NAMES gnuradio-pi_modulators
    HINTS $ENV{PI_MODULATORS_DIR}/lib
        ${PC_PI_MODULATORS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/pi_modulatorsTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PI_MODULATORS DEFAULT_MSG PI_MODULATORS_LIBRARIES PI_MODULATORS_INCLUDE_DIRS)
MARK_AS_ADVANCED(PI_MODULATORS_LIBRARIES PI_MODULATORS_INCLUDE_DIRS)
