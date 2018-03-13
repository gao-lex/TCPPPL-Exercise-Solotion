* 7.1 Get the ‘‘Hello, world!’’ program (§2.2.1) to run. This is not an exercise in program-ming. It is an exercise to test your use of your edit-compile-link-execute tool chain.

``` c++
// program 2.2.1
#include <iostream>

using namespace std;

int main()
{
    std::cout<<"Hello,World!\n";
    return 0;
}
```

``` bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [16:04:10] 
$ g++ p2-2-1.cpp 

# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [16:04:17] 
$ ./a.out 
Hello,World!


```

--- 

* 7.2 Write a program that prints signed if plain chars are signed on your implementation and unsigned otherwise.

``` c++
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    if(CHAR_MIN<0)
        cout << "signed" <<endl;
    else
        cout << "unsigned" <<endl;
    return 0;
}
```

``` bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [16:20:41] 
$ g++ 7-2.cpp 

# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [16:21:20] 
$ ./a.out     
signed


```

---

* 7.3 Find 5 different C++ constructs for which the meaning is undefined (§6.1). Find 5 different C++ constructs for which the meaning is implementation-defined (§6.1).

``` c++

//undefined
char c1 = "hello";
int i1 = "hello" ;
float f1 = "hello";//and so on
//implementation-defined
char c = 256;
int i2 = 65536;//and so on

```

--- 

* 7.4 Find 10 different examples of nonportable(不可移植的) C++ code.

``` c++
int i = 65536;
//and so on
```

---

* 7.5  For each declaration in §6.3, do the following: If the declaration is not a definition, write a definition for it. If the declaration is a definition, write a declaration for it that is not also a definition.

``` c++
char ch {'c'};
string s {"hi"};
int count ;
const double pi {3.1415926535891};//Because we can't assign a value to a const object, it must be initialized
extern int error_number = 0 ;//Warning: 'error_number' has been initialized, but it is declared 'extern'.

const char* name;
const char* season[];
vector<string> people;
struct Date;//can be defined later
int day (Date* );
double sqrt(double d){ return std::sqrt(d);}//#include <cmath>
template<class T> T abs(T );

constexpr int fact(int);
constexpr double zz = 7;//const variable "zz" requires an initializer

using Cmplx = std::complex<double>;//It must be written in this way
struct User {std::string name;int age};
enum class Beer;
namespace NS {int a;}//It must be written in this way

```

---

* 7.6 Write a program that prints the sizes of the fundamental types, a few pointer types, and a few enumerations of your choice. Use the sizeof operator.

``` c++
#include <iostream>
using namespace std;

enum class num:int {zero,one,two,three,four,five,six,seven,eight,nine};

enum class letter:char{green,red,orange};
int main()
{
    cout<<"the sizeof char is " << sizeof(char)<<endl;
    cout<<"the sizeof short is " << sizeof(short)<<endl;
    cout<<"the sizeof int is " << sizeof(int)<<endl;
    cout<<"the sizeof long is " << sizeof(long)<<endl;
    cout<<"the sizeof short* is " << sizeof(short*)<<endl;
    cout<<"the sizeof int* is " << sizeof(int*)<<endl;
    cout<<"the sizeof long* is " << sizeof(long*)<<endl;
    cout<<"the sizeof enum num is " << sizeof(num)<<endl;
    cout<<"the sizeof enum letter is " << sizeof(letter)<<endl;
    return 0;
}
```

``` bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [20:01:57] 
$ g++ 7-6.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [20:03:08] 
$ ./a.out 
the sizeof char is 1
the sizeof short is 2
the sizeof int is 4
the sizeof long is 8
the sizeof short* is 8
the sizeof int* is 8
the sizeof long* is 8
the sizeof enum num is 4
the sizeof enum letter is 1

```

--- 

* 7.7 Write a program that prints out the letters 'a' .. 'z' and the digits '0' .. '9' and their integer values. Do the same for other printable characters. Do the same again but use hexadecimal notation.

``` c++
#include<iostream>
#include<cctype>
#include<ios>
using namespace std;

bool my_isprint(char ch)
{
    return std::isprint(static_cast<unsigned char>(ch));
}

int main()
{
    //ascii between 0~127
    for(auto i=0;i<128;i++)
        if(my_isprint(i))
            cout<<"integer value:   "<< i << "    "
                <<"printable characters:    "<< char(i) << "  "
                <<"hex:    "<< std::hex << i
                <<endl ;
    return 0;
}
```

``` bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [20:21:18] 
$ g++ 7-7.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [20:21:59] 
$ ./a.out               
integer value:   32    printable characters:       hex:    20
integer value:   21    printable characters:    !  hex:    21
integer value:   22    printable characters:    "  hex:    22
integer value:   23    printable characters:    #  hex:    23
integer value:   24    printable characters:    $  hex:    24
integer value:   25    printable characters:    %  hex:    25
integer value:   26    printable characters:    &  hex:    26
integer value:   27    printable characters:    '  hex:    27
integer value:   28    printable characters:    (  hex:    28
integer value:   29    printable characters:    )  hex:    29
integer value:   2a    printable characters:    *  hex:    2a
integer value:   2b    printable characters:    +  hex:    2b
integer value:   2c    printable characters:    ,  hex:    2c
integer value:   2d    printable characters:    -  hex:    2d
integer value:   2e    printable characters:    .  hex:    2e
integer value:   2f    printable characters:    /  hex:    2f
integer value:   30    printable characters:    0  hex:    30
integer value:   31    printable characters:    1  hex:    31
integer value:   32    printable characters:    2  hex:    32
integer value:   33    printable characters:    3  hex:    33
integer value:   34    printable characters:    4  hex:    34
integer value:   35    printable characters:    5  hex:    35
integer value:   36    printable characters:    6  hex:    36
integer value:   37    printable characters:    7  hex:    37
integer value:   38    printable characters:    8  hex:    38
integer value:   39    printable characters:    9  hex:    39
integer value:   3a    printable characters:    :  hex:    3a
integer value:   3b    printable characters:    ;  hex:    3b
integer value:   3c    printable characters:    <  hex:    3c
integer value:   3d    printable characters:    =  hex:    3d
integer value:   3e    printable characters:    >  hex:    3e
integer value:   3f    printable characters:    ?  hex:    3f
integer value:   40    printable characters:    @  hex:    40
integer value:   41    printable characters:    A  hex:    41
integer value:   42    printable characters:    B  hex:    42
integer value:   43    printable characters:    C  hex:    43
integer value:   44    printable characters:    D  hex:    44
integer value:   45    printable characters:    E  hex:    45
integer value:   46    printable characters:    F  hex:    46
integer value:   47    printable characters:    G  hex:    47
integer value:   48    printable characters:    H  hex:    48
integer value:   49    printable characters:    I  hex:    49
integer value:   4a    printable characters:    J  hex:    4a
integer value:   4b    printable characters:    K  hex:    4b
integer value:   4c    printable characters:    L  hex:    4c
integer value:   4d    printable characters:    M  hex:    4d
integer value:   4e    printable characters:    N  hex:    4e
integer value:   4f    printable characters:    O  hex:    4f
integer value:   50    printable characters:    P  hex:    50
integer value:   51    printable characters:    Q  hex:    51
integer value:   52    printable characters:    R  hex:    52
integer value:   53    printable characters:    S  hex:    53
integer value:   54    printable characters:    T  hex:    54
integer value:   55    printable characters:    U  hex:    55
integer value:   56    printable characters:    V  hex:    56
integer value:   57    printable characters:    W  hex:    57
integer value:   58    printable characters:    X  hex:    58
integer value:   59    printable characters:    Y  hex:    59
integer value:   5a    printable characters:    Z  hex:    5a
integer value:   5b    printable characters:    [  hex:    5b
integer value:   5c    printable characters:    \  hex:    5c
integer value:   5d    printable characters:    ]  hex:    5d
integer value:   5e    printable characters:    ^  hex:    5e
integer value:   5f    printable characters:    _  hex:    5f
integer value:   60    printable characters:    `  hex:    60
integer value:   61    printable characters:    a  hex:    61
integer value:   62    printable characters:    b  hex:    62
integer value:   63    printable characters:    c  hex:    63
integer value:   64    printable characters:    d  hex:    64
integer value:   65    printable characters:    e  hex:    65
integer value:   66    printable characters:    f  hex:    66
integer value:   67    printable characters:    g  hex:    67
integer value:   68    printable characters:    h  hex:    68
integer value:   69    printable characters:    i  hex:    69
integer value:   6a    printable characters:    j  hex:    6a
integer value:   6b    printable characters:    k  hex:    6b
integer value:   6c    printable characters:    l  hex:    6c
integer value:   6d    printable characters:    m  hex:    6d
integer value:   6e    printable characters:    n  hex:    6e
integer value:   6f    printable characters:    o  hex:    6f
integer value:   70    printable characters:    p  hex:    70
integer value:   71    printable characters:    q  hex:    71
integer value:   72    printable characters:    r  hex:    72
integer value:   73    printable characters:    s  hex:    73
integer value:   74    printable characters:    t  hex:    74
integer value:   75    printable characters:    u  hex:    75
integer value:   76    printable characters:    v  hex:    76
integer value:   77    printable characters:    w  hex:    77
integer value:   78    printable characters:    x  hex:    78
integer value:   79    printable characters:    y  hex:    79
integer value:   7a    printable characters:    z  hex:    7a
integer value:   7b    printable characters:    {  hex:    7b
integer value:   7c    printable characters:    |  hex:    7c
integer value:   7d    printable characters:    }  hex:    7d
integer value:   7e    printable characters:    ~  hex:    7e
```

---

* 7.8 What, on your system, are the largest and the smallest values of the following types: bool , char , short , int , long , long long , float , double , long double , unsigned and unsigned long .

```c++
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout<<"the smallest values of type bool is  "<<std::numeric_limits<bool>::lowest()<<endl;
    cout<<"the largest values of type bool is  "<<std::numeric_limits<bool>::max()<<endl;

    cout<<"the smallest values of type char is  "<<std::numeric_limits<char>::lowest()<<endl;
    cout<<"the largest values of type char is  "<<std::numeric_limits<char>::max()<<endl;

    cout<<"the smallest values of type short is "<<std::numeric_limits<short>::lowest()<<endl;
    cout<<"the largest values of type short is "<<std::numeric_limits<short>::max()<<endl;
    
    cout<<"the smallest values of type int is   "<<std::numeric_limits<int>::lowest()<<endl;
    cout<<"the largest values of type int is   "<<std::numeric_limits<int>::max()<<endl;
    
    cout<<"the smallest values of type long is  "<<std::numeric_limits<long>::lowest()<<endl;
    cout<<"the largest values of type long is  "<<std::numeric_limits<long>::max()<<endl;
    
    cout<<"the smallest values of type long long is "<<std::numeric_limits<long long>::lowest()<<endl;
    cout<<"the largest values of type long long is "<<std::numeric_limits<long long>::max()<<endl;
    
    cout<<"the smallest values of type float is "<<std::numeric_limits<float>::lowest()<<endl;
    cout<<"the largest values of type float is "<<std::numeric_limits<float>::max()<<endl;
    
    cout<<"the smallest values of type double is    "<<std::numeric_limits<double>::lowest()<<endl;
    cout<<"the largest values of type double is    "<<std::numeric_limits<double>::max()<<endl;
    
    cout<<"the smallest values of type long double is   "<<std::numeric_limits<long double>::lowest()<<endl;
    cout<<"the largest values of type long double is   "<<std::numeric_limits<long double>::max()<<endl;
    
    cout<<"the smallest values of type unsigned is  "<<std::numeric_limits<unsigned>::lowest()<<endl;
    cout<<"the largest values of type unsigned is  "<<std::numeric_limits<unsigned>::max()<<endl;
    
    cout<<"the smallest values of type unsigned long is "<<std::numeric_limits<unsigned long>::lowest()<<endl;
    cout<<"the largest values of type unsigned long is "<<std::numeric_limits<unsigned long>::max()<<endl;
    
    return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [20:38:57] 
$ g++ 7-8.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [20:38:58] 
$ ./a.out               
the smallest values of type bool is  0
the largest values of type bool is  1
the smallest values of type char is   
the largest values of type char is  
the smallest values of type short is -32768
the largest values of type short is 32767
the smallest values of type int is   -2147483648
the largest values of type int is   2147483647
the smallest values of type long is  -9223372036854775808
the largest values of type long is  9223372036854775807
the smallest values of type long long is -9223372036854775808
the largest values of type long long is 9223372036854775807
the smallest values of type float is -3.40282e+38
the largest values of type float is 3.40282e+38
the smallest values of type double is    -1.79769e+308
the largest values of type double is    1.79769e+308
the smallest values of type long double is   -1.18973e+4932
the largest values of type long double is   1.18973e+4932
the smallest values of type unsigned is  0
the largest values of type unsigned is  4294967295
the smallest values of type unsigned long is 0
the largest values of type unsigned long is 18446744073709551615

```

---

* 7.9 What are the sizes (in number of char s) of the types mentioned in §X.7[8]?

> Sizes of C++ objects are expressed in terms of multiples of the size of a char, so by definition the size of a char is 1. The size of an object or type can be obtained using the sizeof operator 

> 所有的C++对象都可以表示成char尺寸的整数倍，因此如果我们令char的尺寸为1，则使用sizeof运算符就能得到任意类型或对象的尺寸。

---

* 7.10 What are the alignments(对齐) (in number of char s) of the types mentioned in §X.7[8]?

> on some machine architectures, the bytes used to hold it must have proper alignment for the hardware to access it efficiently (or in extreme cases to access it at all). For example, a 4-byte int often has to be aligned on a word (4-byte) boundary, and sometimes an 8-byte double has to be aligned on a word (8-byte) boundary.

> 在一些机器的体系结构中，存放变量的字节必须保持一种良好的对齐方式，以便硬件在访问数据资源时足够高效（在极端情况下一次性访问所有数据）。例如，4字节的int应该按字（4字节）的边界排列，而8字节的double也应该按字（8字节）的边界排列。

---

* 7.11 Draw a graph of the integer and fundamental types where a type points to another type if all values of the first can be represented as values of the second on every standards-conform-ing implementation. Draw the same graph for the types on your favorite implementation.

    **TODO**

---

* 7.12 What is the longest local name you can use in a C++ program on your system? What is the longest external name you can use in a C++ program on your system? Are there any restrictions on the characters you can use in a name?

    * C++ imposes no limit on the number of characters in a name(C++没有对名字中所含的字符数量未做限定).However, some parts of an implementation are not under the control of the compiler writer (in particular, the linker), and those parts, unfortunately, sometimes do impose limits.(但是在具体实现中，某些部分并不受编译器的控制(尤其是链接器),而这些部分有可能会限制名字中字符的数量)。
    * restrictions：the identifiers that are keywords cannot be used for other purposes(不能用关键字);the identifiers with a double underscore anywhere are reserved(不能连续出现两个下划线);the identifiers that begin with an underscore followed by an uppercase letter are reserved(不能下划线紧连大写字母开头);the identifiers that begin with an underscore are reserved in the global namespace(函数体外的标识符不能以下划线开头).
---

* 7.13 Write a loop that prints out the values 4 , 5 , 9 , 17 , 12 without using an array or a vector 。

```c++
#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l {4,5,9,17,12};
    for(auto i:l)
        cout<<i<<endl;
    return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [21:39:55] C:1
$ g++ 7-13.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/7 [21:39:57] 
$ ./a.out 
4
5
9
17
12
```
