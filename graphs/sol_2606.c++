#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<bool>chk;
int n, m, cnt = 0;

void DFS(int rt) {
	cnt++;
	chk[rt] = 1;
	
	for (int i = 0; i < v[rt].size(); i++) {
		if (chk[v[rt][i]] == 1) {
			continue;
		}
		DFS(v[rt][i]);
	}
}


int main() {
	cin >> n >> m;
	
	v.resize(n + 1);
	chk.resize(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		v[p].push_back(q);
		v[q].push_back(p);
	}

	DFS(1);

	cout << cnt - 1;

	return 0;
}