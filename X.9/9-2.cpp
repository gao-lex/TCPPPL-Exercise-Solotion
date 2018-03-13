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