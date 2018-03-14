#include <iostream>
#include <string>

using namespace std;

char * itoa(int i, char b[])
{
	int temp{i};
	int power{1};
	while (temp /= 10)
		power++;
	for (auto j = 0; j < power; j++)
	{
		int k = i % 10;
		b[power - 1 - j] = k+'0';
		i /= 10;
	}
	return b;
}

int main()
{
	int i{1234567890};
	char p[20]{};
	std::cout << itoa(i,p) << std::endl;
	return 0;
}