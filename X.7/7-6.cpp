#include <iostream>
using namespace std;

enum class num:int {zero,one,two,three,four,five,six,seven,eight,nine};

enum class letter:char{green,red,orange};
int main()
{
    cout<<"the sizeof char is " << sizeof(char)<<endl;
    cout<<"the sizeof short is " << sizeof(short)<<endl;
    cout<<"the sizeof int is " << sizeof(int)<<endl;
    cout<<"the sizeof long is " << sizeof(long)<<endl;
    cout<<"the sizeof short* is " << sizeof(short*)<<endl;
    cout<<"the sizeof int* is " << sizeof(int*)<<endl;
    cout<<"the sizeof long* is " << sizeof(long*)<<endl;
    cout<<"the sizeof enum num is " << sizeof(num)<<endl;
    cout<<"the sizeof enum letter is " << sizeof(letter)<<endl;
    return 0;
}