#include <iostream>
#include <string>
using namespace std;

void print_months(string a[],int i = 12)
{
	for (auto j = 0; j < i; j++)
		cout << a[j] << endl;
	
}

int main()
{
	string months[]{ "January","February","March","April",
					"May","June","July","August","September",
					"October","November","December" };
	print_months(months);
	return 0;
}