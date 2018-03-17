* 1 question u can see X.11 15

* 2 Allocate so much memory using new that bad_alloc is thrown. Report how much memory was allocated and how much time it took. Do this twice: once not writing to the allocated memory and once writing to each element.


**if not Initialization,end-begin is zero**

```c++
//because of Initialization,this program is very slow
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
			size += 100000;

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

```


---

* 3 Write a simple loop calculating a sum of elements (like std::accumulate() ). Write it in a dozen(一打) or more ways using for-statements, range-for statements, the for_each() algorithm, using indices(index的复数), pointers, and iterators, using ‘‘plain code’’, function objects, and lambdas, and using different element types. See if you can find any performance differences between the different versions.

```
int accumulate_indices(int a[],int size)
{
    int sum = 0;
    for (auto i =0;i<size;i++)
	    sum += a[i];
    return sum;
}

int accumulate_pointer(int a[], int size)
{
    int sum = 0;
    for (auto i = a; i-a<size; i++)
	    sum += *i;
    return sum;
}

int accumulate_iterator(int *b, int *e)
{
    int sum = 0;
    for_each(b,e,[sum](int x){sum+=x});
    return sum;
}

int a[] {1,2,3,4};
int sum;
for(auto i:a)
    sum+=i;
```

---

* 4 Define an apply(v,f) that applies a function f to each element of v assumed to be a vector<Shape∗> . Test apply() with a a variety of functions, function objects, and lambdas. Note that by capturing variables from a lambda or storing values in a function object, you can call Shape functions that takes arguments without having to have f() take explicit arguments. Hint: there is a variety of ways of specifying apply() ’s argument types; experiment.

```c++
#include <iostream>
#include <vector>
using namespace std;

void apply(vector<int>& v, void (*f)(int &x))
{
	for (auto& i : v)
		f(i);
}
void add(int &x)
{
	x += 1;
}

int main()
{
	vector<int> v{ 0,1,2,3,4,5,6 };
	apply(v, add);//v = {1,2,3,4,5,6,7}
	apply(v, [](int &x) { x -= 1; }); //v = {0,1,2,3,4,5,6}
	return 0;
}
```

---

* 5 Find a program of a few thousand lines of code, preferably a program used for a realworld task, rather than an exercise solution. Count the number of casts (of all kinds). If not already done, classify all casts by turning them into named casts. Eliminate as many static_cast s, reinterpre_cast s, and const_cast s as possible. This will most likely involve adding specific type conversion functions, templates, etc.

