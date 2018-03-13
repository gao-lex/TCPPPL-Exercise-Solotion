#include <iostream>

void f(char v[])
{
    for(int i=0;v[i]!=0;++i)
        std::cout<<v[i]<<std::endl;
}