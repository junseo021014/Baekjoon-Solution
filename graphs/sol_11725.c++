#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;
vector<int> graph[100001];
int	par_node[100001];
int isVisited[100001];
int n;

void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	isVisited[cur] = 1;

	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		
		for (int i = 0; i < graph[parent].size(); ++i) {
			int child = graph[parent][i];
			if (!isVisited[child]) {
				par_node[child] = parent;
				isVisited[child] = 1;
				q.push(child);
			}
		}
	}
}


int main() {
	fastio;

	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);

	for (int j = 2; j <= n; ++j) {
		cout << par_node[j] << "\n";
	}

	return 0;
}