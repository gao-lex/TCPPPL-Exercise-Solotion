#include <iostream>

using namespace std;

int distanceBetweenCharPtr(char* s1,char* s2)
{
    return s2-s1;
}

int main()
{
    char s[] = {"hello"};
    char* s2 = &s[2];
    cout<<distanceBetweenCharPtr(s,s2)<<endl;
    cout<<distanceBetweenCharPtr(s2,s)<<endl;
    return 0;
}