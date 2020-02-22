list(APPEND HelloCopperSpice_INCLUDES
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.hpp
)

list(APPEND HelloCopperSpice_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.ui
   #qrc_hellolunch.cpp
)

# run rcc to generate qrc output
# COPPERSPICE_RESOURCES()
   #${CMAKE_CURRENT_SOURCE_DIR}/../hellolunch.qrc
# )

# run uic to generate source
COPPERSPICE_RESOURCES(
   ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.ui
)

add_executable(HelloCopperSpice
   ${HelloCopperSpice_SOURCES}
)

target_include_directories(HelloCopperSpice
   PRIVATE
   ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(HelloCopperSpice
   CopperSpice::CsCore
   CopperSpice::CsGui
)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   # disable console on windows
   target_link_libraries(HelloCopperSpice -lnetapi32 -lmpr -mwindows)
endif()

install(TARGETS HelloCopperSpice DESTINATION .)

cs_copy_library(CsCore)
cs_copy_library(CsGui)
cs_copy_library(CsNetwork)
cs_copy_library(CsOpenGL)
cs_copy_library(CsScript)
cs_copy_library(CsSql)
cs_copy_library(CsSvg)
cs_copy_library(CsXml)
cs_copy_library(CsXmlPatterns)

cs_copy_plugins(CsGui)

