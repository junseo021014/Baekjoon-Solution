#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> p, c, w, b;

void memory(int k) {
	graph.resize(n + 1);
	p.resize(n + 1);
	c.resize(n + 1);
	w.resize(n + 1);
	b.resize(n + 1);
}

long long paint_tree(int cur, bool isWhite) {
	long long price = !isWhite ? b[cur] : w[cur];

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		price += paint_tree(next, !isWhite);
	}
	return price;
}

int main() {
	fastio;
	cin >> n; // 정점 개수

	// 메모리 할당
	memory(n);

	// 그래프 생성
	for (int i = 0; i < (n - 1); ++i) {
		cin >> p[i] >> c[i];
		graph[p[i]].push_back(c[i]);
	}

	// white, black 비용 입력
	for (int j = 0; j < n; ++j) {
		cin >> w[j] >> b[j];
	}
	
	cout << min(paint_tree(0, 0), paint_tree(0, 1));

	return 0;
}