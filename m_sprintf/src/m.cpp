#include "../include/m_format.h"
#include "../include/m_sprintf.h"


int main()
{
    // MyNumber m = { "1fsdfsdf", "2", "3", "4" "\n//////////////////////"};
    // m.print();  // 1 2 3 4
    std::string a = "I ";
    std::string b = "am ";
    std::string c = "print ";
    std::string d = "test ";
    std::string e = ", ";
    std::string f = "bye";
    std::string g = "!";
    std::string ret = m_sprint("[Log] this is log : %s: %d, %s: %d", c.c_str(), 6, d.c_str(), 8);
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