#include<iostream>

using namespace std;

//alias to unsigned char
using uchar = unsigned char;
//alias to const unsigned char
using const_uchar = const unsigned char;
//alias to pointer to integer
using ptr_int = int*;
//alias to pointer to pointer to char
using ptr_ptr_char = char**;
//alias to pointer to array of char
using ptr_arr_char = char(*)[];
//alias to array of 7 pointers to int
using arr_7ptr_int = int *[7];
//alias to pointer to an array of 7 pointers to int
using ptr_arr_7ptr_int = int *(*)[7];
//alias to array of 8 arrays of 7 pointers to int
using arr_8arr_7ptr_int = int *[][8][7];

int main()
{
	char ca[10]{};//{0 '\0', 0 '\0', 0 '\0', ...}
	char(*pac)[10] = &ca; // same as ca
	ptr_arr_char pac2 = {};//0x00000000；type：char[0] *
	int* ia[7]{};//{0x00000000, 0x00000000, ...}；type：int *[7]
	arr_7ptr_int api = { };//{0x00000000, 0x00000000, ...}；type：int *[7]
	//arr_7ptr_int api = ia;
	/*error:c++ 没有为数组提供内置的拷贝操作。
	 * 不允许用一个数组初始化另一个数组（即使两个数组的类型完全一样也不行）
	 * 数组不支持赋值操作 
	 * int v[5] {0,1,2,3,4};
	 * int v2 = v;//error 不允许拷贝数组
	 * int v3[5];
	 * v3 = v;//error 不存在数组的赋值操作
	 */
	int *(*papi)[7] = &ia;//{0x00000000 , 0x00000000 , ...}	type：int *[7] *
	ptr_arr_7ptr_int papi2 = &ia;//same as papi

	/*int *aapi [][8][7] = {}; //can't use in this way
	arr_8arr_7ptr_int aapi2 = {};*/ //can't use in this way
	return 0;
}