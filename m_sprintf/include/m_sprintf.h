/**
 * @file m_sprintf.h
 * @author zs 
 * @brief packaging sprintf
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#ifndef __M_SPRINTF_H__
#define __M_SPRINTF_H__

#include <iostream>
#include <string>


template<typename... Types>
std::string m_sprint(const char* format, const Types&... args)
{
    std::string reString = {};
    char buff[1024];
    sprintf(buff, format, args...);
    reString += buff;
    // std::cout << reString << std::endl;
    return reString;
}
// void* t = ::operator new(512);  

#endif //_M_PRINTF_H__