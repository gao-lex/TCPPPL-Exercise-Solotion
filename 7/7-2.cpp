#include <iostream>
#include <climits>
using namespace std;

int main()
{
    if(CHAR_MIN<0)
        cout << "signed" <<endl;
    else
        cout << "unsigned" <<endl;
    return 0;
}