#include<iostream>
#include<cctype>
#include<ios>
using namespace std;

bool my_isprint(char ch)
{
    return std::isprint(static_cast<unsigned char>(ch));
}

int main()
{
    //ascii between 0~127
    for(auto i=0;i<128;i++)
        if(my_isprint(i))
            cout<<"integer value:   "<< i << "    "
                <<"printable characters:    "<< char(i) << "  "
                <<"hex:    "<< std::hex << i
                <<endl ;
    return 0;
}