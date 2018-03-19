#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
	
	for (int i = 1; i < argc; i++)
	{
		FILE* fp = fopen(argv[i],"r");
		int c; // note: int, not char, required to handle EOF
		while ((c = std::fgetc(fp)) != EOF) { // standard C I/O file reading loop
			std::putchar(c);
		}
		fclose(fp);
        cout<<endl;
	}
	return 0;
}

