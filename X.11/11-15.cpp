#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a[]{ 0,1,0,2,0,3,0,4,0,5 };
	vector<int> v;
	for (auto i : a)
		if (i != 0)
			v.push_back(i);
	for (auto i : v)
		cout << i << endl;
	return 0;
}

