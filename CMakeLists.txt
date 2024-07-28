cmake_minimum_required(VERSION 3.16)
project(GitLogPlugin)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(KF5 REQUIRED COMPONENTS I18n TextEditor)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

set(gitlogplugin_SRCS src/plugin.cpp)

add_library(gitlogplugin MODULE ${gitlogplugin_SRCS})
target_link_libraries(gitlogplugin Qt5::Core Qt5::Widgets KF5::TextEditor KF5::I18n)

install(TARGETS gitlogplugin DESTINATION ${PLUGIN_INSTALL_DIR})
