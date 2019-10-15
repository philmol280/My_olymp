#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

#define int long long

using namespace std;

vector<int> arr;
vector<int> ans;

unordered_map<char, vector<int>> symbols;

signed main() {
	string s, w; // we need to count number of subsequences w in s
	cin >> s;
	cin >> w;
	for (int i = 0; i < w.size(); i++) {
		symbols[w[i]].push_back(i);
	}
	vector <int> num_pref(w.size());
	for (int i = 0; i < s.size(); i++) {
		auto a = symbols[s[i]];
		for (auto el : a) {
			if (el != 0)
				num_pref[el] += num_pref[el - 1];
			else
				num_pref[el]++;
		}
	}
	cout << num_pref[w.size() - 1];
	return 0;
}
