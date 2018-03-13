#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> vs;
	for (string s; cin >> s; )
		if (s != "quit" && find(vs.begin(),vs.end(),s)==vs.end())
			vs.push_back(s);
		else break;
	cout << "raw order：" << endl;
	for (auto i : vs)
		cout << "	" << i << endl;
	cout << "sorted order:" << endl;
	sort(vs.begin(), vs.end());
	for (auto i : vs)
		cout << "	" << i << endl;
	return 0;
}