* 1 Find where the standard library headers are kept on your system. List their names. Are any nonstandard headers kept together with the standard ones? Can any nonstandard headers be `#included` using the `<>` notation?

```bash
c++ stamdard library: /usr/include/c++/5.4.0
c++ stamdard library: /usr/include/c++/5
c stamdard library: /usr/include/
```
---

* 2 Where are the headers for nonstandard ‘‘foundation’’ libraries kept?

```bash

```

---

* 3 Write a program that reads a source file and writes out the names of files `#included`. Indent(缩进) file names to show files `#included` by included files. Try this program on some real source files (to get an idea of the amount of information included).

```c++
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
```

```bash
# gaolex @ gaolex-hasee in ~/Documents/TCPPPL-Exercise-Solotion/X.17 on git:master x [18:53:52] 
$ g++ 17-3.cpp -std=c++11                            

# gaolex @ gaolex-hasee in ~/Documents/TCPPPL-Exercise-Solotion/X.17 on git:master x [18:55:00] 
$ ./a.out /usr/include/stdio.h                       
<libio.h>
<bits/stdio_lim.h>
<bits/sys_errlist.h>
```

---

* 4 Modify the program from the previous exercise to print the number of comment(注释) lines, the number of non-comment lines, and the number of non-comment, whitespace-separated(分割)  words for each file #included.

---

* 5 An external include guard is a construct that tests outside the file it is guarding and includes only once per compilation. Define such a construct, devise a way of testing it, and discuss its advantages and disadvantages compared to the include guards described in §15.3.3. Is there any significant run-time advantage to external include guards on your system?


---

* 6 How is dynamic linking achieved on your system? What restrictions are placed on dynamically linked code? What requirements are placed on code for it to be dynamically linked?

动态链接是如何在你的系统上实现的？对动态链接的代码有什么限制？代码对动态链接的要求是什么？

---

* 7 Open and read 100 files containing 1500 characters each. Open and read one file containing 150,000 characters. Is there a performance difference? What is the highest number of files that can be simultaneously open on your system? Consider these questions in relation to the use of #include files.

打开并读取100个包含1500个字符的文件。打开并读取一个包含15万个字符的文件。是否有性能差异？您的系统上可以同时打开的文件数量最多？请考虑这些问题与 #include 文件的使用有关。

---

* 8 Modify the desk calculator so that it can be invoked from main() or from other functions as a simple function call.

修改桌面计算器, 使它可以从主 () 或其他函数调用作为一个简单的函数调用。

---

* 9 Draw the ‘‘module dependency diagrams’’ (§15.3.2) for the version of the calculator that used error() instead of exceptions (§14.2.2).

为使用错误 () 而不是异常的计算器版本绘制 "模块依赖关系图" (§15.3 2) (§14.2. 2)