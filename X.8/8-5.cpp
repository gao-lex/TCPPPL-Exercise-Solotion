#include <iostream>

using namespace std;

int distanceBetweenCharPtr(int* s1,int* s2)
{
    return s2-s1;
}

int main()
{
    int s[] = {1,2,3,4,5,6};
    int* s2 = &s[5];
    cout<<distanceBetweenCharPtr(s,s2)<<endl;
    cout<<distanceBetweenCharPtr(s2,s)<<endl;
    return 0;
}