* 1 Fully parenthesize the following expressions:

```c++
    a = b + c ∗ d << 2 & 8
    a & 077 != 3
    a == b || a == c && c < 5
    c = x != 0
    0 <= i < 7
    f(1,2)+3
    a = − 1 + + b −− − 5
    a = b == c ++
    a = b = c = 0
    a[4][2] ∗= ∗ b ? c : ∗ d ∗ 2
    a−b,c=d
```

```c++
a = ((b + (c * d)) << 2) & 8;
(a & 077) != 3;
(a == b) || ((a == c) && (c < 5));
c = (x != 0);
(0 <= i) < 7;
f(1, 2) + 3;
a = (-1 ++)(b--) - 5; //complie error
a = (b == (c++));
a = (b = (c = 0));
a[4][2] *= (*b ? c : (*d * 2));
(a - b), (c = d);//逗号运算符
```

---

* 2 Read a sequence of possibly whitespace-separated (name,value) pairs, where the name is a single whitespace-separated word and the value is an integer or a floating-point value. Compute and print the sum and mean for each name and the sum and mean for all names. Hint: §10.2.8.

```c++
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

void solotion(map<string, vector<float>>& m)
{
	string s{};
	float f{};
	while (cin >> s >> f)
		m[s].push_back(f);
	cout.width(10); cout << left << "name";
	cout.width(10); cout << left << "sum";
	cout.width(10); cout << left << "mean" << endl;
	for (auto p : m)
	{
		cout.width(10); cout << left << p.first;
		float sum = std::accumulate(p.second.begin(), p.second.end(), 0);
		cout.width(10); cout << left << sum;
		float mean = sum / p.second.size();
		cout.width(10); cout << left << mean << endl;
	}
}

int main()
{
	map<string, vector<float>> msf{};
	solotion(msf);
	return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [22:16:31] 
$ g++ 11-2.cpp -std=c++11 

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [22:17:02] 
$ ./a.out
zxc 1
zxc 2
zxc 3
asd 4
qwe 6
qwe 8
name      sum       mean      
asd       4         4         
qwe       14        7         
zxc       6         2         

```

---

* 3 Write a table of values for the bitwise logical operations (§11.1.1) for all possible combinations of `0` and `1` operands.

|`&`|0|1|
|:---:|:---:|:---:|
|0|0|0|
|1|0|1|

|`|`|0|1|
|:---:|:---:|:---:|
|0|0|1|
|1|1|1|

|`^`|0|1|
|:---:|:---:|:---:|
|0|0|1|
|1|1|0|

---

* 4 Write 5 expressions for which the order of evaluation is undefined. Execute them to see what one or – preferably – more implementations do with them.

```c++
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int f(const int a)
{
	cout << "f(int) is running" << endl;
	return a;
}

int g(int a)
{
	cout << "g(int) is running" << endl;
	return a;
}

int f1(int a,int b )
{
	cout << "in f1(int a,int b) a is " << a << " b is " << b << endl;
	return a;
}

int main()
{
	cout << "expression 1" << endl;
	int x = f(2) + g(3);


	int i = 2;
	int a[10]{  };
	cout << endl << "expression 2" << endl;
	a[i] = i++;
	cout << "i is " << i << endl;
	for (auto j : a)
		cout << j << " ";
	cout << endl;


	cout << endl << "expression 3" << endl;
	i = 3;
	f1(a[i], i++);

    //and so on
	return 0;
}


```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [22:48:31] 
$ g++ 11-4.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [22:48:34] 
$ ./a.out 
expression 1
f(int) is running
g(int) is running

expression 2
i is 3
0 0 0 2 0 0 0 0 0 0 

expression 3
in f1(int a,int b) a is 0 b is 3


```
---

* 5 What happens if you divide by zero on your system? What happens in case of overflow and underflow?

```c++
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{

	int a = -100000000000000000000000;
	int b = 1000000000000000000000000;
	int c = 0;
	cout << 5 / c << endl;
	return 0;
}


```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [22:48:36] 
$ g++ 11-5.cpp -std=c++11
11-5.cpp:12:11: 警告：整数常量值超出其类型 [默认启用]
  int a = -100000000000000000000000;
           ^
11-5.cpp:13:10: 警告：整数常量值超出其类型 [默认启用]
  int b = 1000000000000000000000000;
          ^
11-5.cpp: 在函数‘int main()’中:
11-5.cpp:12:11: 警告：隐式常量转换溢出 [-Woverflow]
  int a = -100000000000000000000000;
           ^
11-5.cpp:13:10: 警告：隐式常量转换溢出 [-Woverflow]
  int b = 1000000000000000000000000;
          ^

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [22:51:56] 
$ ./a.out 
[1]    2796 floating point exception  ./a.out

```

---

* 6 Fully parenthesize(括号) the following expressions:
```c++
    ∗p++
    ∗−−p
    ++a−−
    (int∗)p−>m
    ∗p.m
    ∗a[i]
```

```c++
	*(p++);
	*(--p);
	++(a--);
	((int*)p)->m;
	(*p).m;
	*(a[i]);
```

---

* 7  Implement and test these functions: strlen() , which returns the length of a C-style string; strcpy() , which copies a C-style string into another; and strcmp() , which compares two C-style strings. Consider what the argument types and return types ought to be. Then compare your functions with the standard library versions as declared in <cstring> ( <string.h> ) and as specified in §43.4.

```c++
unsigned int strlen(const char * p)
{
	int i = 0;
	while (*(p + i) != '\0')
		i++;
	return i;
}

void strcpy(char *dest, const char* from)
{
	int i = 0;
	while (*(from + i) != '\0')
	{
		dest[i] = from[i];
		i++;
	}
}

bool strcmp(const char* a,const char* b)
//0 means a bigger,1 means b bigger
{
	int i = 0;
	while (*(a+i)!='\0'&& *(b+i)!='\0')
	{
		if (*(a + i) > *(b + i))
			return 0;
		else if (*(a + i) < *(b + i))
			return 1;
		i++;
	}
}

```

---

* 8 Modify the program from §X.11[2] to also compute the median.

```c++
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

void solotion(map<string, vector<float>>& m)
{
	string s{};
	float f{};
	while (cin >> s >> f)
		m[s].push_back(f);
	cout.width(10); cout << left << "name";
	cout.width(10); cout << left << "sum";
	cout.width(10); cout << left << "mean";
	cout.width(10); cout << left << "median" << endl;
	for (auto p : m)
	{
		cout.width(10); cout << left << p.first;
		float sum = std::accumulate(p.second.begin(), p.second.end(), 0);
		cout.width(10); cout << left << sum;
		float mean = sum / p.second.size();
		cout.width(10); cout << left << mean;
		cout.width(10); cout << left << p.second[p.second.size()/2] << endl;
	}
}

int main()
{
	map<string, vector<float>> msf{};
	solotion(msf);
	return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [0:37:29] 
$ g++ 11-8.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [0:38:34] 
$ ./a.out                
zxc 1               
zxc 2
zxc 3
zxc 4
asd 5
qwe 6
qwe 8
zxc 5
name      sum       mean      median    
asd       5         5         5         
qwe       14        7         8         
zxc       15        3         3  
```

---

* 9 Write a function cat() that takes two C-style string arguments and returns a string that is the concatenation of the arguments. Use new to find store for the result.

```c++
#include <iostream>
#include <string>
using namespace std;

string* cat(const char *a, const char *b)
{
	string as = string(a);
	string bs = string(b);
	return new string(as + bs);
}

int main()
{
	const char *a = { "qwerty" };
	const char *b = { "zxcvbn" };
	auto s = cat(a, b);
	cout << *s << endl;
	return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [2:40:01] C:1
$ g++ 11-9.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [2:40:03] 
$ g++ 11-9.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [2:40:04] 
$ ./a.out 
qwertyzxcvbn

```


---

* 10 Write a function rev() that takes a C-style string argument and reverses the characters in it. That is, after rev(p) the last character of p will be the first, etc.

```c++
#include <iostream>
#include <string>
using namespace std;

void rev(char *a)
{
	int n = strlen(a);
	for (auto i = 0; i < n/2; i++)
		swap(*(a+i), *(a + n-i-1));

}

int main()
{
	char a[10] = {  };
	cin >> a;
	rev(a);
	for (auto i :a)
		cout << i;
	return 0;
}


```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [3:02:07] 
$ g++ 11-10.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [3:02:08] 
$ ./a.out 
123456
654321
```

---

* 11 Type in the calculator example and get it to work. Do not ‘‘save time’’ by using an already entered text. You’ll learn most from finding and correcting ‘‘little silly errors.’’

```c++
//code in 11-11.cpp
// there is still some bug i can't find
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [3:02:13] 
$ g++ 11-11.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [3:21:06] 
$ ./a.out 
5+6
11
6*9
54
6-1
5
4/2
2


```

---

* 12 Modify the calculator to report line numbers for errors.

```c++
//i can't do this
```

---

* 13 Allow a user to define functions in the calculator. Hint: Define a function as a sequence of operations just as a user would have typed them. Such a sequence can be stored either as a character string or as a list of tokens. Then read and execute those operations when the function is called. If you want a user-defined function to take arguments, you will have to invent a notation for that.

```c++
//i can't do this
```
---

* 14 Convert the desk calculator to use a symbol structure instead of using the static variables number_value and string_value .

```c++
//i can't do this
```

---

* 15 Copy all even non-zero elements of an int[] into a vector<int> . Use a pointer and ++ for the traversal.

**i think this question may be X.12 1**

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a[]{ 0,1,0,2,0,3,0,4,0,5 };
	vector<int> v;
	for (auto i : a)
		if (i != 0)
			v.push_back(i);
	for (auto i : v)
		cout << i << endl;
	return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [3:37:52] 
$ g++ 11-15.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.11 on git:master x [3:37:55] 
$ ./a.out                 
1
2
3
4
5

```