#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int w, h;
int maps[51][51];
bool isVisited[51][51];
int dy[8] = { 1,-1,0,0,1,1,-1,-1 }; 
int dx[8] = { 0,0,1,-1,1,-1,-1,1 };

void DFS(int xcur, int ycur) {
    // 이미 방문한 곳이면 탈출
    if (isVisited[xcur][ycur])
        return;

    // 방문 표시
    isVisited[xcur][ycur] = true;

    // 8방향을 돌면서 대각선까지 확인
    for (int i = 0; i < 8; ++i) {
        int nextX = xcur + dx[i];
        int nextY = ycur + dy[i];

        // 다음 x, y 좌표의 범위 지정
        if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w) {

            // 방문하지 않았고, 섬이면 DFS 실행
            if (!isVisited[nextX][nextY] && maps[nextX][nextY]) {
                DFS(nextX, nextY);
            }
        }
    }
}

// 초기화 함수
void reset() {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            maps[i][j] = 0;
            isVisited[i][j] = false;
        }
    }
}

int main() {
    fastio;

    // 지도에 입력 받기
    while (true) {
        cin >> w >> h;

        // 0 0이면 종료
        if (w == 0 && h == 0)
            break;

        // 지도에 섬, 바다 입력
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> maps[i][j];
            }
        }
        // 섬의 개수
        int cnt = 0;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!isVisited[i][j] && maps[i][j]) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
        reset();
    }

    return 0;
}
