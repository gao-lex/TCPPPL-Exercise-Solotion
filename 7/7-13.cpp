#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l {4,5,9,17,12};
    for(auto i:l)
        cout<<i<<endl;
    return 0;
}