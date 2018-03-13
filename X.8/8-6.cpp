#include <iostream>

using namespace std;

class testArray
{
public:
	int a6[10] = { 30,31,32,33,34,35,36,37,38,39 };
};

int a1[] = { 0,1,2,3,4,5,6,7,8,9 };

int main()
{
	int a2[] = { 10,11,12,13,14,15,16,17,18,19 };
	int *a3 = new int[10];//默认初始化：未初始化
	int *a4 = new int[10]();//初始化为0
	int *a5 = new int[10]{ 20,21,22,23,24,25,26,27,78,29 };//初始化
	testArray ta;
	*(a1 - 1) = 1;
	*(a1 + 11) = 1;

	*(a2 - 2) = 2;
	*(a2 + 12) = 2;

	*(a3 - 3) = 3;
	*(a3 + 13) = 3;

	*(a4 - 4) = 4;
	*(a4 + 14) = 4;

	*(a5 - 5) = 5;
	*(a5 + 15) = 5;

	*(ta.a6 - 6) = 6;
	*(ta.a6 + 16) = 6;
    
	delete[] a3;
	delete[] a4;
	delete[] a5;
	return 0;
}