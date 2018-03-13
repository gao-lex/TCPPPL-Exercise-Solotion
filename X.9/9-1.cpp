#include <iostream>
using namespace std;
struct largest_size
{
	char c;
	int i;
	bool b;
	long l;
	long double ld;
	double d;
};

struct smallest_size
{
	long double ld;//16
	double d;//8
	long l;//8
	int i;//4
	bool b;//1
	char c;//1

};
int main()
{
	cout << sizeof(largest_size) << endl;
	cout << sizeof(smallest_size) << endl;
	return 0;
}