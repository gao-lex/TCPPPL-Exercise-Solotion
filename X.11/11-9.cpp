#include <iostream>
#include <string>
using namespace std;

string* cat(const char *a, const char *b)
{
	string as = string(a);
	string bs = string(b);
	return new string(as + bs);
}

int main()
{
	const char *a = { "qwerty" };
	const char *b = { "zxcvbn" };
	auto s = cat(a, b);
	cout << *s << endl;
	return 0;
}

