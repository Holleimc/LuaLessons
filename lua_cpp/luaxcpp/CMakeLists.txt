cmake_minimum_required(VERSION 2.8.12)

project(main)

# find_package(Lua REQUIRED) 
# if(Lua_FOUND)
# message(STATUS "TTTTTTTTTTTTT")
# endif()
# include_directories(${Lua_INCLUDE_DIR})
# message(STATUS "Found Hello: ${Lua_INCLUDE_DIR}")
include_directories("C:/Lua/5.1/include/")
include_directories("C:/Lua/5.1/lib/")
link_libraries(lua5.1.lib)
# include_directories ("${PROJECT_SOURCE_DIR}/lua54/include")
# add_library(MathFunctions ..\lua54\include\lua.hpp)
# set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)

add_executable(main main.cpp)

# target_link_libraries (main  ${EXTRA_LIBS})
target_link_libraries(main "${Lua_LIBRARIES}")
