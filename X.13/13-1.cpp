#include <iostream>
#include <tuple>
#include <functional>
using namespace std;

void f1(char *, int &)
{
	return;
}
void(*pf1) (char *, int &) = f1;//void (*pf1) = &f1;
void f2(void(*) (char *, int &));
using p1 = void(*) (char *, int &);
p1 f3();
tuple<char *, int &> f4(p1)
{
	char *a = new char{ 'a' };
	int *p = new int{ 1 };
	cout << "in f4 ,address of char is " << long(a) << endl;
	cout << "in f4 ,value of char is " << *a << endl;
	cout << "in f4 ,address of int is " << long(p) << endl;
	cout << "in f4 ,value of int is " << *p << endl;
	cout << "-------" << endl;
	return make_tuple(a, std::ref(*p));
}



int main()
{
	auto ans = f4(f1);
	cout << "in main ,address of get<0>(ans) is " << long(get<0>(ans)) << endl;
	cout << "in main ,value of get<0>(ans) is " << *get<0>(ans) << endl;
	*get<0>(ans) = 'b';
	cout << "now ,in main ,address of get<0>(ans) is " << long(get<0>(ans)) << endl;
	cout << "now ,in main ,value of get<0>(ans) is " << *get<0>(ans) << endl;
	cout << "---------" << endl;
	cout << "in main ,address of get<1>(ans) is " << long(&get<1>(ans)) << endl;
	cout << "in main ,value of get<1>(ans) is " << get<1>(ans) << endl;
	get<1>(ans) = 2;
	cout << "now ,in main ,address of get<1>(ans) is " << long(&get<1>(ans)) << endl;
	cout << "now ,in main ,value of get<1>(ans) is " << get<1>(ans) << endl;
	delete get<0>(ans);
	delete &get<1>(ans);
	return 0;
}

