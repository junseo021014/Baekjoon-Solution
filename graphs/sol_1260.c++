#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;
vector<int> graph[1001]; 
int isVisited[1001];
int n, m, v;

void dfs(int cur) {
	if (isVisited[cur])
		return;

	cout << cur << " ";
	isVisited[cur] = 1;
	
	sort(graph[cur].begin(), graph[cur].end());

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
			dfs(next);
	}

}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	isVisited[start] = 1;

	sort(graph[start].begin(), graph[start].end());

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (!isVisited[next]) {
				isVisited[next] = 1;
				q.push(next);
			}
		}
	}
}


int main() {
	fastio;

	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(v);
	cout << "\n";
	fill(isVisited, isVisited + n + 1, 0);
	bfs(v);

	return 0;
}
