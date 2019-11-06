cmake_minimum_required(VERSION 3.2)

project(otus_cpp_range VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

include(conanbuildinfo.cmake)
conan_basic_setup()

add_executable(range "main.cpp" "library.h" "library.cpp")

set_target_properties(range PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")

install(TARGETS range RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_NAME "range")
set(CPACK_PACKAGE_CONTACT "dedi4@mail.ru")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
include(CPack)
