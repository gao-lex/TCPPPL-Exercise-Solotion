* 1 Write declarations for the following: a function taking arguments of type pointer to character and reference to integer and returning no value; a pointer to such a function; a function taking such a pointer as an argument; and a function returning such a pointer. Write the definition of a function that takes such a pointer as an argument and returns its argument as the return value. Hint: Use a type alias ( using ).

```c++
#include <iostream>
#include <tuple>
#include <functional>
using namespace std;

void f1(char *, int &)
{
	return;
}
void(*pf1) (char *, int &) = f1;//void (*pf1) = &f1;
void f2(void(*) (char *, int &));
using p1 = void(*) (char *, int &);
p1 f3();
tuple<char *, int &> f4(p1)
{
	char *a = new char{ 'a' };
	int *p = new int{ 1 };
	cout << "in f4 ,address of char is " << long(a) << endl;
	cout << "in f4 ,value of char is " << *a << endl;
	cout << "in f4 ,address of int is " << long(p) << endl;
	cout << "in f4 ,value of int is " << *p << endl;
	cout << "-------" << endl;
	return make_tuple(a, std::ref(*p));
}



int main()
{
	auto ans = f4(f1);
	cout << "in main ,address of get<0>(ans) is " << long(get<0>(ans)) << endl;
	cout << "in main ,value of get<0>(ans) is " << *get<0>(ans) << endl;
	*get<0>(ans) = 'b';
	cout << "now ,in main ,address of get<0>(ans) is " << long(get<0>(ans)) << endl;
	cout << "now ,in main ,value of get<0>(ans) is " << *get<0>(ans) << endl;
	cout << "---------" << endl;
	cout << "in main ,address of get<1>(ans) is " << long(&get<1>(ans)) << endl;
	cout << "in main ,value of get<1>(ans) is " << get<1>(ans) << endl;
	get<1>(ans) = 2;
	cout << "now ,in main ,address of get<1>(ans) is " << long(&get<1>(ans)) << endl;
	cout << "now ,in main ,value of get<1>(ans) is " << get<1>(ans) << endl;
    delete get<0>(ans);
	delete &get<1>(ans);
	return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [17:52:20] 
$ g++ 13-1.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [17:56:53] 
$ ./a.out                
in f4 ,address of char is 26677264
in f4 ,value of char is a
in f4 ,address of int is 26677296
in f4 ,value of int is 1
-------
in main ,address of get<0>(ans) is 26677264
in main ,value of get<0>(ans) is a
now ,in main ,address of get<0>(ans) is 26677264
now ,in main ,value of get<0>(ans) is b
---------
in main ,address of get<1>(ans) is 26677296
in main ,value of get<1>(ans) is 1
now ,in main ,address of get<1>(ans) is 26677296
now ,in main ,value of get<1>(ans) is 2
```

---

* 2 What does the following mean? What would it be good for?
`using riffi = int (&) (int, int);`

this is a reference to function

u can see more in [https://stackoverflow.com/questions/480248/function-references](https://stackoverflow.com/questions/480248/function-references)

---

* 3 Write a program like ‘‘Hello, world!’’ that takes a name as a command-line argument and writes ‘‘Hello, name ! ’’. Modify this program to take any number of names as arguments and to say hello to each.

```c++
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
		cout << "Hello " << argv[i] << " !" << endl;
	return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [19:06:28] 
$ g++ 13-3.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [19:08:45] 
$ ./a.out tom jerry gaolex
Hello tom !
Hello jerry !
Hello gaolex !
```

---

* 4 Write a program that reads an arbitrary(任意的) number (possibly limited to some maximum number) of files whose names are given as command-line arguments and writes them one after another on cout . Because this program concatenates its arguments to produce its output, you might call it cat .

```c++
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


```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [21:39:09] 
$ ./a.out file1 file2
this is file1this is file2%                                                                                                                                                                                                                                                   

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [21:39:17] 
$ g++ 13-4.cpp       

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [21:40:28] 
$ ./a.out file1 file2
this is file1 line1
this is file1 line2
this is file2 line1
this is file2 line2

```

---

* 5 Convert a small C program to C++. Modify the header files to declare all functions called and to declare the type of every argument. Where possible, replace #define s with enum , const , constexpr , or inline . Remove extern declarations from .cpp files and if necessary convert all function definitions to C++ function definition syntax. Replace calls of malloc() and free() with new and delete . Remove unnecessary casts.

i will find peogram in c latter

---

* 6 Modify the result of §X.13[5] by eliminating arrays and ‘‘naked’’ new s and delete s.Hint: vector and array .

need to be done

---

* 7 Implement ssort() (§12.5) using a more efficient sorting algorithm. Hint: sort() and qsort() .

quicksort


* 8 Consider:
```c++
	struct Tnode {
		string word;
		int count;
		Tnode∗ left;
		Tnode∗ right;
	};
```
Write a function for entering new words into a tree of Tnode s. Write a function to write out a tree of Tnode s. Write a function to write out a tree of Tnode s with the words in alphabetical order. Modify Tnode so that it stores (only) a pointer to an arbitrarily long word storedas an array of characters on free store using new . Modify the functions to use the new definition of Tnode .



---

* 9 Write a function to invert a two-dimensional array. Hint: §7.4.2.

```cpp
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
```

---

* 10 Write an encryption program that reads from cin and writes the encoded characters to cout . You might use this simple encryption scheme: the encrypted form of a character c is cˆkey[i] , where key is a string passed as a command-line argument. The program uses the characters in key in a cyclic manner until all the input has been read. Re-encrypting encoded text with the same key produces the original text. If no key (or a null string) is passed, then no encryption is done.

```cpp
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	char p[] = { "password" };
	for (size_t i = 0; argv[1][i] != '\0'; i++)
		cout << (argv[1][i] ^ p[i % 8]) << endl;
	return 0;
}

```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [1:33:50] 
$ g++ 13-10.cpp           

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.13 on git:master x [1:34:04] 
$ ./a.out showMeTheAnswers
3
9
28
4
58
10
38
12
21
32
29
0
0
10
0
23

```

---

* 11 Write a program to help decipher messages encrypted with the method described in §X.13[10] without knowing the key. Hint: See David Kahn: The Codebreakers, Macmillan, 1967, New York, pp. 207-213.



---

* 12 Without using copy and paste, implement and test TEA (the Tiny Encryption Algorithm). D.J. Wheeler and R.M. Needham: TEA, a tiny encryption algorithm. Lecture Notes in Computer Science 1008: 363366. [http://143.53.36.235:8080/tea.htm](http://143.53.36.235:8080/tea.htm).

---

* 13 How would you choose names for pointer to function types defined using a type alias?

i would choose a name convenient me

---

* 14 Look at some programs to get an idea of the diversity of styles of names actually used. How are uppercase letters used? How is the underscore used? When are short names such as i and x used?



---

* 15 What is wrong with these macro definitions?
```c++
	#define PI = 3.141593;/*#define PI 3.1415926*/
	#define MAX(a,b) a>b?a:b/*#define MAX(a,b) (((a)>(b))?(a):(b))*/
	#define fac(a) (a)∗fac((a)−1)/*递归调用*/
```

---

* 16 Write a macro processor that defines and expands simple macros (like the C preproces\sor does). Read from cin and write to cout . At first, don’t try to handle macros with argu\ments. Hint: The desk calculator (§10.2) contains a symbol table and a lexical analyzer that you could modify.




---

* 17 Write an error function that takes a printf -style format string containing %s , %c , and %d directives(指令) and an arbitrary(任意的) number of arguments. Don’t use printf() . Look at §43.3 if you don’t know the meaning of %s , %c , and %d . Use <cstdarg> .

---

* 18 Implement a useful subset of print() from §12.2.5.

---

* 19 Add functions such as sqrt() , log() , and sin() to the desk calculator from §10.2. Hint: Predefine the names and call the functions through an array of pointers to functions. Don’t forget to check the arguments in a function call.

---

* 20 Write a factorial function that does not use recursion.

```c++
int fac(int i)
{
	for (auto a = 2; a < i; a++)
		i *= a;
	return i;
}
```

---

* 21 Write functions to add one day, one month, and one year to a Date as defined in §X.9[4]. Write a function that gives the day of the week for a given Date . Write a function that gives the Date of the first Monday following a given Date .