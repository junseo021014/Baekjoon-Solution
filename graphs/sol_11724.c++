#include <bits/stdc++.h>

using namespace std;
 
vector<int> v[1001];
bool chk[1001];
int n, m, cnt = 0;

void DFS(int rt) {
	chk[rt] = 1;
	
	for (int i = 0; i < v[rt].size(); i++) {
		if (chk[v[rt][i]] == 1) {
			continue;
		}
		DFS(v[rt][i]);
	}
}


int main() {
	//정점 n, 간선 m
	cin >> n >> m;

	//간선의 양 끝점 입력받기
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		v[p].push_back(q);
		v[q].push_back(p);
	}

	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0) {
			DFS(i);
			cnt++;
		}
	}

	if (m == 0) {
		cnt = 1;
	}

	cout << cnt;

	return 0;
}
