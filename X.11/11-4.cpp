#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int f(const int a)
{
	cout << "f(int) is running" << endl;
	return a;
}

int g(int a)
{
	cout << "g(int) is running" << endl;
	return a;
}

int f1(int a,int b )
{
	cout << "in f1(int a,int b) a is " << a << " b is " << b << endl;
	return a;
}

int main()
{
	cout << "expression 1" << endl;
	int x = f(2) + g(3);


	int i = 2;
	int a[10]{  };
	cout << endl << "expression 2" << endl;
	a[i] = i++;
	cout << "i is " << i << endl;
	for (auto j : a)
		cout << j << " ";
	cout << endl;


	cout << endl << "expression 3" << endl;
	i = 3;
	f1(a[i], i++);

    //and so on
	return 0;
}

