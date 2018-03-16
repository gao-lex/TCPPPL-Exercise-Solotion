#include <iostream>
#include <cstring>
using namespace std;

void rev(char *a)
{
	int n = strlen(a);
	for (auto i = 0; i < n/2; i++)
		swap(*(a+i), *(a + n-i-1));

}

int main()
{
	char a[10] = {  };
	cin >> a;
	rev(a);
	for (auto i :a)
		cout << i;
	return 0;
}
