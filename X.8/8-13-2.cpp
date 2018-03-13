#include <iostream>
void f(char v[])
{
    for(char* p=v;*p!=0;++p)
        std::cout<<*p<<std::endl;
}