#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int n, m;
int maps[101][101];
bool isVisited[101][101]; 
int dist[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int xcur, int ycur) {
    queue<pair<int, int>> q; // int형 pair 객체 큐 생성
    q.push(make_pair(xcur, ycur)); // 현재 x, y 좌표로 q에 요소 추가
    isVisited[xcur][ycur] = true; // 방문 표시
    dist[xcur][ycur] = 1; // 1을 거쳐간 횟수

    // 큐가 빌 때까지
    while (!q.empty()) {
        int x = q.front().first; // 맨 앞 큐에서 첫 번째 int 요소 -> x 좌표
        int y = q.front().second; // 맨 앞 큐에서 두 번째 int 요소 -> y좌표

        q.pop(); // 요소 삭제

        // 동서남북 한 칸씩 이동하며 길 찾기
        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            // 맵의 범위를 벗어나지 않으면서 방문하지 않은 1로 된 좌표를 찾음
            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                if (!isVisited[nextX][nextY] && maps[nextX][nextY]) {
                    dist[nextX][nextY] = dist[x][y] + 1; // 1을 거쳐간 횟수를 이전 좌표에서의 값에서 +1
                    q.push(make_pair(nextX, nextY));
                    isVisited[nextX][nextY] = true;
                }
            }
        }
    }

    // 도착점 n, m 좌표에서의 거리 반환
    return dist[n - 1][m - 1];
}

int main() {
    fastio;

    cin >> n >> m;

    // 맵에 미로 입력받기
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j) {
            maps[i][j] = str[j] - '0';
        }
    }

    cout << bfs(0, 0);

    return 0;
}
