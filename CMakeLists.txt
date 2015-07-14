cmake_minimum_required(VERSION 2.6)
project(etakeyboard)
find_package(KDE4 REQUIRED)

include_directories(${KDE4_INCLUDES} ${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(etaKeyboard_SRCS reader.cpp etaKeyboard.cpp main.cpp)

qt4_automoc(${etaKeyboard_SRCS})

add_executable(etakeyboard ${etaKeyboard_SRCS})

target_link_libraries(etakeyboard ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${KDE4_KDEUI_LIBS}
                      ${X11_XTest_LIB} 
                      ${X11_X11_LIB} 
                      ${X11_LIBS})

install(TARGETS etakeyboard RUNTIME DESTINATION bin)
