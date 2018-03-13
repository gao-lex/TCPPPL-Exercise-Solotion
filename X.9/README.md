* 1 Define a struct with a member of each of the types bool , char , int , long , double , and long double . Order the members so as to get the largest size of the struct and the smallest size of the struct .

```c++
#include <iostream>
using namespace std;
struct largest_size
{
	char c;
	int i;
	bool b;
	long l;
	long double ld;
	double d;
};

struct smallest_size
{
	long double ld;//16
	double d;//8
	long l;//8
	int i;//4
	bool b;//1
	char c;//1

};
int main()
{
	cout << sizeof(largest_size) << endl;
	cout << sizeof(smallest_size) << endl;
	return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.9 on git:master x [7:58:27] 
$ g++ 9-1.cpp

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.9 on git:master x [8:01:22] 
$ ./a.out    
64
48

```
---

* 2 Define a table of the names of months of the year and the number of days in each month. Write out that table. Do this twice; once using an array of char for the names and an array for the number of days and once using an array of structures, with each structure hold- ing the name of a month and the number of days in it.

```c++
#include <iostream>
#include <sstream>
#include <iomanip>
struct Month {
	const char *name;
	int days;
};

using namespace std;

int main() {
	const int num_of_monthes_one_year = 12;
	const char *names[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int days[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::cout << setw(10) << "Month" << setfill(' ') << setw(10) << "Days" << setfill(' ') << std::endl;
	for (int i = 0; i != num_of_monthes_one_year; ++i)
		std::cout << setw(10) << names[i] << setfill(' ') << setw(10) << days[i] << setfill(' ') << std::endl;
	Month months[]{
		{ "January", 31 },
		{ "February", 29 },
		{ "March", 31 },
		{ "April", 30 },
		{ "May", 31 },
		{ "June", 30 },
		{ "July", 31 },
		{ "August", 31 },
		{ "September", 30 },
		{ "October", 31 },
		{ "November", 30 },
		{ "December", 31 }
	};
	std::cout << setw(10) << "Month" << setfill(' ') << setw(10) << "Days" << setfill(' ') << std::endl;
	for (int i = 0; i != num_of_monthes_one_year; ++i)
		std::cout << setw(10) << months[i].name << setfill(' ') << setw(10) << months[i].days << setfill(' ') << std::endl;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.9 on git:master x [8:29:42] C:1
$ g++ 9-2.cpp -std=c++11

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.9 on git:master x [8:34:33] 
$ ./a.out               
     Month      Days
   January        31
  February        29
     March        31
     April        30
       May        31
      June        30
      July        31
    August        31
 September        30
   October        31
  November        30
  December        31
     Month      Days
   January        31
  February        29
     March        31
     April        30
       May        31
      June        30
      July        31
    August        31
 September        30
   October        31
  November        30
  December        31
```

---

* 3 Find an example where it would make sense to use a name in its own initializer.

```c++
struct Link{
    Link* previous;
    Link* successor;
}
```

---

* 4 Define a struct Date to keep track of dates. Provide functions that read Dates from input, write Dates to output, and initialize a Date with a date.

```c++
#include<iostream>
#include<string>
using namespace std;

struct Date {
	string year;
	string month;
	string day;
	friend istream &operator>>(istream &is, Date &d) { 
		cin >> d.year >> d.month >> d.day;
		return is;
	}
	friend ostream &operator<<(ostream &os, const Date &d) { 
		os << d.year << "-" << d.month << "-" << d.day << endl; 
		return os;
	}
};

int main()
{
	struct Date d;
	cin >> d;
	cout << d;
	return 0;
}
```

```bash
# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.9 on git:master x [9:07:26] 
$ g++ 9-4.cpp 

# gaolex @ cv in ~/TCPPPL-4th-Exercises/X.9 on git:master x [9:07:33] 
$ ./a.out 
2018
3
14
2018-3-14
```

---

* 5 Implement an enum called Season with enumerators spring , summer , autumn , and winter . Define operators ++ and −− for Season . Define input ( >> ) and output ( << ) operations for Season , providing string values. Provide a way to control the mapping between Season values and their string representations. For example, I might want the strings to reflect the Danish names for the seasons. For further study, see Chapter 39.

```c++
enum class Season{ spring, summer, autumn, winter };
Season& operator++(Season& s) {
    int new_s = static_cast<int>(s);
    new_s++;
    if (new_s > 3) new_s = 0;
    return s = static_cast<Season>(new_s);
}
Season& operator--(Season& s) {
    int new_s = static_cast<int>(s);
    new_s--;
    if (new_s <0) new_s = 3;
    return s = static_cast<Season>(new_s);
}
```

