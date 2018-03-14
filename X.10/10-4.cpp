#include<iostream>
#include<string>

int atoi(const char* c)
{
	int r{};
	for (auto i = 0; *(c + i) != '\0'; i++)
	{
		r *= 10;
		r += *(c + i) - '0';
	}
	return r;
}

int atoi(int x)
{
	return x;
}

int atoi(const char c)
{
	return c - '0';
}

int main()
{
	int a{ 017 };
	int b{ 0x17 };
	int c{ 17 };
	const char *p = "123456789";
	const char d{ '1' };
	std::cout << a << std::endl;
	std::cout << atoi(a) << std::endl;
	std::cout << b << std::endl;
	std::cout << atoi(b) << std::endl;
	std::cout << c << std::endl;
	std::cout << atoi(c) << std::endl;
	std::cout << p << std::endl;
	std::cout << atoi(p) << std::endl;
	std::cout << d << std::endl;
	std::cout << atoi(d) << std::endl;
	return 0;
}