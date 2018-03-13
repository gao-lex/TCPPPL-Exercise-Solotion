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