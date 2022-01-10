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
#include <sstream>
#include <string>
#include <vector>
#include <stdarg.h>

class MyNumber
{
public:
    MyNumber(const std::initializer_list<std::string> &v) 
    {
        for (auto itm : v) {
            //mVec.push_back(itm);
            m_string += itm;
        }
    }

    void print() 
    {
        std::cout << m_string << std::endl;
    // for (auto itm : mVec) {
    //     std::cout << itm << " ";
    // }
    }
private:
    std::vector<int> mVec;
    std::string m_string;
};

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