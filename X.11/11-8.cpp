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

