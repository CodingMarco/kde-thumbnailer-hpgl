project(kde-thumbnailer-hpgl)
cmake_minimum_required(VERSION 3.16.0)

set(SHARED_MIME_INFO_MINIMUM_VERSION "0.30")

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECompilerSettings)
include(KDECMakeSettings)
include(FeatureSummary)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(KF5 REQUIRED COMPONENTS KIO Archive)

find_package(SharedMimeInfo REQUIRED)

set(hpglthumbnail_SRCS hpglcreator.cpp)

add_library(hpglthumbnail MODULE ${hpglthumbnail_SRCS})
target_link_libraries(hpglthumbnail PRIVATE
     Qt5::Widgets KF5::KIOWidgets KF5::Archive
)

add_executable(hpglthumbnail_test test.cpp hpglcreator.cpp)
target_link_libraries(hpglthumbnail_test
     Qt5::Widgets KF5::KIOWidgets KF5::Archive
)

install(TARGETS hpglthumbnail DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES hpglthumbnail.desktop DESTINATION ${SERVICES_INSTALL_DIR})
install(FILES hpgl.xml DESTINATION ${XDG_MIME_INSTALL_DIR})

update_xdg_mimetypes(${XDG_MIME_INSTALL_DIR})
