#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
	cout << "swap by pointer" << endl;
	int c = *a;
	*a = *b;
	*b = c;
}

void swap(int &a, int &b)
{
	cout << "swap by references" << endl;
	int c = a;
	a = b;
	b = c;
}

int main()
{
	int i = 3, j = 4;
	cout << "i = " << i << "	j = " << j << endl;
	swap(&i, &j);
	cout << "i = " << i << "	j = " << j << endl;
	swap(i, j);
	cout << "i = " << i << "	j = " << j << endl;
	return 0;
}