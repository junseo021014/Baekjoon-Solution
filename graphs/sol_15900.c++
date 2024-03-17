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
		int next = graph[cur][i]; // ���� ��带 �ڽ� ��� �߿� ��
		// ���� �ڽ� ��带 �湮���� �ʾ����� DFS �����
		DFS(next, level + 1);
		// ���� ����� ��
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
	// ������ ���� n (2 <= n <= 500,000)
	cin >> n;

	// �޸� �Ҵ� �� �ʱ�ȭ
	memory(n);

	// �׷��� �����
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	//��Ʈ ��忡�� ��� ���� �������� ���̸� DFS�� ���� ���ϱ�
	if (n != 2) {
		DFS(1, 0);
	}
	else {
		cnt = 1;
	}
	printWinable(cnt);

	return 0;
}