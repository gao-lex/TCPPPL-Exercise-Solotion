#include <iostream>
#include <string>

int count_pairs(std::string str, std::string pair) {
	int count = 0;
	for (int i = 0; i != str.length() - 1; ++i)
		if (str.substr(i, 2) == pair)
			++count;
	return count;
}

int count_pairs(char* str, char* pair) {
	int count = 0;
	int i = 0;
	while (str[i + 1]) {
		if (str[i] == pair[0] && str[i + 1] == pair[1])
			++count;
		++i;
	}
	return count;
}

int main() {
	std::string haystack = "xabaacbaxabb";
	std::string needle = "ab";
	std::cout << count_pairs(haystack, needle) << std::endl;
	std::cout << count_pairs(haystack.c_str(), needle.c_str()) << std::endl;
    return 0;
}