#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int n;

int solve(int m) {
	fastio;
	map<string, int> mp;
	vector<vector<int>> w;
	vector<bool> vst;
	w.resize(2001);
	vst.resize(2001, 0);
	int leaf_node_cnt = 0, idx = 0;
	for (int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		string word = "";
		vector<int> v;
		for (char ch : str) {
			if (ch == '.' || ch == ',' || ch == ':') {
				if (mp[word] == 0) mp[word] = ++idx;
				v.push_back(mp[word]);
				word = "";
				continue;
			}
			word += ch;
		}
		//cout << v[0] << " -> ";
		for (int k : v) {
			if (k == v[0]) continue;
			w[v[0]].push_back(k);
			//cout << k << " ";
		}
		//cout << "\n";
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int target = q.front(); q.pop();
		if (vst[target]) continue;
		vst[target] = 1;
		//cout << target << "-> target\n";
		for (int next : w[target]) {
			if (vst[next]) continue;
			//cout << next << " ";
			q.push(next);
		}
		//cout << "\n";
		if (w[target].size() == 0) leaf_node_cnt++;
	}
	return leaf_node_cnt;
}

int main() {
	cin >> n;
	while (n != 0) {
		cout << solve(n) << "\n";
		cin >> n;
	}
	return 0;
}