cmake_minimum_required(VERSION 3.16)

project(Citadel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/base/rules.hpp
    src/base/rules.cpp

    src/libs/nlohmann/json.hpp
    
    src/parsers/configurationloader.cpp
    src/parsers/configurationloader.hpp

)

include(GNUInstallDirs)
install(TARGETS Citadel
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
