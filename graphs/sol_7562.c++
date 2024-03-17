#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int t;
int maps[301][301];
bool isVisited[301][301];
int dist[301][301];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int sx, sy, ax, ay;

void bfs(int xcur, int ycur, int length) {
    queue <pair<int, int>> q;
    q.push(make_pair(xcur, ycur)); // 현재 좌표로 큐 요소 추가
    isVisited[xcur][ycur] = true; // 방문 표시
    dist[xcur][ycur] = 0; // 이동한 횟수

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        // 찾으려던 도착 지점에 도달하면
        if (x == ax && y == ay) {
            cout << dist[x][y] << "\n";
            return;
        }

        // 나이트가 이동할 수 있는 8가지의 경우
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < length && ny >= 0 && ny < length) {
                if (!isVisited[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1; // 이전 이동 거리의 +1
                    q.push(make_pair(nx, ny));
                    isVisited[nx][ny] = true;
                }
            }
        }
    }
}

void reset(int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            maps[i][j] = 0;
            isVisited[i][j] = false;
            dist[i][j] = 0;
        }
    }
}

void sol() {
    // 체스판의 한 변의 길이 입력
    int length;
    cin >> length;

    // 현재 나이트의 위치, 이동할 위치 입력;
    cin >> sx >> sy;
    cin >> ax >> ay;

    // 이동할 점의 좌표를 1로 지정
    maps[ax][ay] = 1;

    bfs(sx, sy, length);

    reset(length);
}

int main() {
    fastio;

    cin >> t;

    while (t--) {
        sol();
    }
   
    return 0;
}