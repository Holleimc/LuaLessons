#include <iostream>
#include "swap.h"

using namespace std;

int main()
{
    int a = 56;
    int b = 65;
    printf("before: \t");
    printf("%3d%3d\n", a, b);
    swap(a, b);
    printf("after: \t");
    printf("%3d%3d\n", a, b);
    return 0;
}