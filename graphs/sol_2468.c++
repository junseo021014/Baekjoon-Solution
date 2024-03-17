#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int height, n;
int maps[101][101];
bool isVisited[101][101];
int dx[4] = { 1, -1, 0, 0 }; 
int dy[4] = { 0, 0, 1, -1 };

void DFS(int xcur, int ycur, int height) {
    // 이미 방문한 곳이면 나가기
    if (isVisited[xcur][ycur])
        return;

    isVisited[xcur][ycur] = true;

    // 동서남북으로 한 칸씩 이동하면서 안전 구역 찾기
    for (int i = 0; i < 4; ++i) {
        int x = xcur + dx[i];
        int y = ycur + dy[i];

        // x좌표 y 좌표 범위가 maps 내에서 작동하기
        if (x >= 0 && x < n && y >= 0 && y < n) {
            if (!isVisited[x][y] && maps[x][y] > height) {
                DFS(x, y, height);
            }
        }
    }
}

// 높이마다 다르므로 방문 초기화
void reset() {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            isVisited[i][j] = false;
        }
    }
}

int main() {
    fastio;

    int cnt = 0;
    int max_area;

    cin >> n;

    // 높이 입력받기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maps[i][j];
        }
    }

    max_area = 0;
    height = 100;

    // 최대 높이 100에서 1씩 감소시키며 모든 케이스 비교
    while (height >= 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!isVisited[i][j] && maps[i][j] > height) {
                    DFS(i, j, height);
                    cnt++;
                }
            }
        }

        // 최대 안전구역 개수보다 큰 경우에만 초기화
        if (max_area < cnt) {
            max_area = cnt;
        }

        // 높이 낮춰서 실행하므로 cnt, isVisited 초기화
        cnt = 0;
        height--;
        reset();
    }
    cout << max_area;

    return 0;
}
