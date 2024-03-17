#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph; 
vector<bool> isVisited;
int n, a, b, cnt = 0;

void DFS(int cur, int level) {
	if (isVisited[cur] == 1) {
		return;
	}

	isVisited[cur] = 1;
	
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i]; // 다음 노드를 자식 노드 중에 고름
		// 다음 자식 노드를 방문하지 않았으면 DFS 재실행
		DFS(next, level + 1);
		// 리프 노드일 때
		if (graph[cur].size() == 1 && cur != 1) {
			cnt += level;
		}
	}
}

void memory(int n) {
	graph.resize(n + 1);
	isVisited.resize(n + 1, 0);
}

void printWinable(int cnt) {
	if (cnt % 2 == 0) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
}

int main() {
	// 정점의 개수 n (2 <= n <= 500,000)
	cin >> n;

	// 메모리 할당 및 초기화
	memory(n);

	// 그래프 만들기
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	//루트 노드에서 모든 리프 노드까지의 높이를 DFS를 통해 구하기
	if (n != 2) {
		DFS(1, 0);
	}
	else {
		cnt = 1;
	}
	printWinable(cnt);

	return 0;
}
