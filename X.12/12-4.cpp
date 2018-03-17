#include <iostream>
#include <vector>
using namespace std;

void apply(vector<int>& v, void (*f)(int &x))
{
	for (auto& i : v)
		f(i);
}
void add(int &x)
{
	x += 1;
}

int main()
{
	vector<int> v{ 0,1,2,3,4,5,6 };
	apply(v, add);//v = {1,2,3,4,5,6,7}
	apply(v, [](int &x) { x -= 1; }); //v = {0,1,2,3,4,5,6}
	return 0;
}