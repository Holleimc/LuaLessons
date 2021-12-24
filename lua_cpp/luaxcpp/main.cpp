#include <iostream>
#include <Lua.hpp>

lua_State* L;

int main()
{
    //lua operation
    L = lua_open();                 //open lua
    luaL_openlibs(L);               //loading the base library
    luaL_dofile(L, "hello.lua");    //execute the script
    lua_close(L);                   //close lua

    system("pause");
    return 0;
}