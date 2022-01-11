#include "../include/m_format.h"
#include "../include/m_sprintf.h"


int main()
{
    // MyNumber m = { "1fsdfsdf", "2", "3", "4" "\n//////////////////////"};
    // m.print();  // 1 2 3 4
    std::string a = "id";
    std::string b = "data";
    int id = 6666;
    int data = 2022;
    std::string ret = m_sprint("[Log] this is a log : %s: %d, %s: %d", a.c_str(), id, b.c_str(), data);
    std::cout << ret << std::endl;


    //------------------------------------------------------------------------------------------------------------------
    
    // int is = 6;
    // short sis = 1;
    // bool bs = 1;
    // unsigned int uis = 66;
    // long ls = 666;
    // double ds = 66.6;
    // float fs = 6.6;
    // const char* ccs = "zzzz";
    // char cs = 'a';
    // std::string sss = "ssssssssss";
    // unsigned long uls = 6666;
    // format("[TestLog]:",uls,", aaa%s", "int:", is, "short:", sis, "bool:", bs, "unsigned int:", uis, "long:", 
    // ls, "double:", ds, "float:", fs, "char:", cs, "const char*:", ccs, "std::string:", sss, "unsignde long:", uls);

    return 0;
}