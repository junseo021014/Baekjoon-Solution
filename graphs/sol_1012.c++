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
	// 방문 표시
	isVisited[x][y] = 1;

	// 동서남북으로 한칸씩 움직이면서 dfs 실행
	for (int i = 0; i < 4; ++i) {
		int X = x + xx[i];
		int Y = y + yy[i];

		if (X >= 0 && X < m && Y >= 0 && Y < n && ground[X][Y] && !isVisited[X][Y])
			dfs(X, Y);
	}
}

int sol(int m, int n, int k) {
	int x, y;

	// (x, y) 좌표에 배추 입력
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		ground[x][y] = 1;
	}
	
	// 필요한 지렁이 수
	cnt = 0;

	// 좌표를 훑으면서 배추가 있으면 dfs실행
	for (int j = 0; j < m; ++j) {
		for (int p = 0; p < n; ++p) {
			// 배추가 있고, 방문하지 않았다면 dfs 실행하고 주위에 배추가 없어 dfs 종료시 cnt 증가
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
