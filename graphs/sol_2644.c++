#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

vector<vector<int>> graph;
vector<bool> isVisited;
int chon_cnt;
int cnt = 0;
int n, m, a, b;

void dfs(int cur, int find) {
	if (isVisited[cur] == 1)
		return;

	isVisited[cur] = 1;
	cnt++;

	for (int i = 0; i < graph[cur].size(); ++i) {
		
		int next = graph[cur][i];
		if (next == find) {
			chon_cnt = cnt;
			isVisited[next] = 1;
			return;
		}
		else {
			dfs(next, find);
		}
	}
	cnt--;
	return;
}

void memory(int k) {
	graph.resize(k + 1);
	isVisited.resize(k + 1, 0);
}

int main() {
	fastio;

	cin >> n >> a >> b >> m;
	memory(n);

	int x, y;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(a, b);

	chon_cnt == 0 ? cout << "-1" : cout << chon_cnt;

	return 0;
}