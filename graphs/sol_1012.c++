#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int t, m, n;
int ground[51][51] = {0, };
bool isVisited[51][51] = {0, };
int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };
int cnt = 0;

void dfs(int x, int y) {
	// �湮 ǥ��
	isVisited[x][y] = 1;

	// ������������ ��ĭ�� �����̸鼭 dfs ����
	for (int i = 0; i < 4; ++i) {
		int X = x + xx[i];
		int Y = y + yy[i];

		if (X >= 0 && X < m && Y >= 0 && Y < n && ground[X][Y] && !isVisited[X][Y])
			dfs(X, Y);
	}
}

int sol(int m, int n, int k) {
	int x, y;

	// (x, y) ��ǥ�� ���� �Է�
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		ground[x][y] = 1;
	}
	
	// �ʿ��� ������ ��
	cnt = 0;

	// ��ǥ�� �����鼭 ���߰� ������ dfs����
	for (int j = 0; j < m; ++j) {
		for (int p = 0; p < n; ++p) {
			// ���߰� �ְ�, �湮���� �ʾҴٸ� dfs �����ϰ� ������ ���߰� ���� dfs ����� cnt ����
			if (ground[j][p] == 1 && !isVisited[j][p]) {
				dfs(j, p);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	fastio;

	int k, x, y;

	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> m >> n >> k;

		int result = sol(m, n, k);

		cout << result << "\n";

		memset(ground, 0, sizeof(ground));
		memset(isVisited, 0, sizeof(isVisited));
	}

	return 0;
}