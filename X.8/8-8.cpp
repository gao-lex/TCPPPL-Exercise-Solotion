#include <iostream>
#include <string>
using namespace std;


int main()
{
	char str[] = "a short string";
	string s = "a short string";
	cout << "size of char str[] = \"a short string\" is " << sizeof(str) << endl;
	cout << "length of string \"a short string\" is " << s.length() << endl;
	return 0;
}