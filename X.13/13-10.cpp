#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	char p[] = { "password" };
	for (size_t i = 0; argv[1][i] != '\0'; i++)
		cout << (argv[1][i] ^ p[i % 8]) << endl;
	return 0;
}
