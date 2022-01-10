/**
 * @file m_format.h
 * @author zs 
 * @brief Template argument + String stream implements parameter formatting
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#ifndef __M_FORMAT_H__
#define __M_FORMAT_H__

#include <iostream>
#include <sstream>
#include <string>

//--------------------------------------------------------------------------------------------------------
//模板参数+string流 ---> 输出参数格式化
template<typename T>
std::string valueToString(const T& firstArg)
{
    std::ostringstream os;  
    os<<firstArg;  
    std::string result;  
    std::istringstream is(os.str());
    std::string tmp;
    while(is >> tmp)
    {
        result += tmp;
        result += ' ';
    }
    
    return result;
}

void splice(std::string& dest)
{

}

template<typename T, typename... Types>
void splice(std::string& dest, const T& firstArg, const Types&... args)
{
    if(typeid(dest) != typeid(std::string))
    {
        return;
    }
    // std::string& ret = dest;
    std::string tmp = valueToString(firstArg);
    dest += tmp;

    if (sizeof...(args) != 0)
    {
        splice(dest, args...);
    }
}

template<typename T, typename... Types>
int format(const T& firstArg, const Types&... args)
{
    if(1)
    {
        std::string ret = {};
        splice(ret, firstArg, args...);
        std::cout << ret << std::endl;
        return 1;
    }
    return 0;
}

#endif //_M_FORMAT_H__