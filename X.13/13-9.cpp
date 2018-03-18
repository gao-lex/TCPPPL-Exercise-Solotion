#include <iostream>
#include <cstdio>
using namespace std;
void invert_two_dim_array(int *a, int dim1,int dim2)
{
	for (size_t i = 0; i < dim1*dim2/2; i++)
		swap(*(a + i), *(a + dim1 * dim2 - 1 - i));
}
int main(int argc, char *argv[])
{
	int a[3][5] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	invert_two_dim_array(&a[0][0], 3, 5);
	return 0;
}