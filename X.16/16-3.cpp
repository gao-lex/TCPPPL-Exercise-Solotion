#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MY_MAXLINE = 99;
const int MY_MAXFILENAME = 99;

int main(int argc,char *argv []) {
    FILE* fp = fopen(argv[1],"r");
    char line[MY_MAXLINE] {};
    while(fgets(line,MY_MAXLINE,fp)!=NULL) {
        if (strncmp("#include",line,8)==0){
            cout<<string(line).substr(9,MY_MAXFILENAME);
        }
}
    fclose(fp);
    return 0;
}