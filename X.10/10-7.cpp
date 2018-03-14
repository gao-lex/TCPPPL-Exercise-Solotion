#include <iostream>
#include <string>

using namespace std;

/*
there is some comments
*/

string& strip(string& s)
{
	while (s.find("//") ||  s.find_first_of("/*"))
	{
		auto pos1 = s.find_first_of("//");
		if (pos1==std::string::npos)
			break;
		auto pos2 = s.find_first_of("\n", pos1);
		s.erase(pos1, pos2-pos1+1);
		auto pos3 = s.find_first_of("/*");
		if (pos3 == std::string::npos)
			break;
		auto pos4 = s.find_first_of("*/",pos3);
		s.erase(pos3, pos4 - pos3 + 1);
	}
	return s;
}

int main()
{
	string s{ };
	cin >> s;
	cout << strip(s) << endl;
	return 0;
}