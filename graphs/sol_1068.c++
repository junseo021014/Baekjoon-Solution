#include <bits/stdc++.h>

using namespace std; 

vector<vector<int>> v;
vector<int> leaf_node_cnt;
vector<int> p;

void DFS(int idx) {

	if (v[idx].size() == 0) {
		leaf_node_cnt[idx] = 1;
		return;
	}

	for (int i = 0; i < v[idx].size(); i++) {
		int child = v[idx][i];
		DFS(child);
	}

	for (int i = 0; i < v[idx].size(); i++) {
		int child = v[idx][i];
		leaf_node_cnt[idx] += leaf_node_cnt[child];
	}

}

int main() {
	int n;
	cin >> n;
	v.resize(n);
	leaf_node_cnt.resize(n, 0);
	int rt;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		p.push_back(k);
		if (k != -1) {
			v[k].push_back(i);
		}
		else {
			rt = i;
		}
	}
	DFS(rt);
	int m;
	cin >> m;

	if (m == rt) {
		cout << 0;
	}
	else if (v[p[m]].size() == 1) {
		cout << leaf_node_cnt[rt] - leaf_node_cnt[m] + 1;
	}
	else {
		cout << leaf_node_cnt[rt] - leaf_node_cnt[m];
	}

	return 0;
}
