#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> times;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		times.push_back({start, 1});
		times.push_back({end, -1});
	}