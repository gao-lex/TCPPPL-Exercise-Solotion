#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	long long size = 0;
	while (true)
	{
		clock_t begin;
		clock_t end;
		try {
			begin = clock();
            
			char *p = new char[size]{};
			size += 100000000;
            cout<<size<<endl;
			delete[] p;
		}
		catch (bad_alloc){
			end = clock();
			cout << "in my machine ,maximum allocation " << size << " bytes" << endl;
			cout << "it takes " << 1000* double(end - begin)/ CLOCKS_PER_SEC <<" ms"<<endl;
			break;
		}
	}
	
	return 0;
}

