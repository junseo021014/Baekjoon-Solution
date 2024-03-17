#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int w, h;
int maps[51][51];
bool isVisited[51][51];
int dy[8] = { 1,-1,0,0,1,1,-1,-1 };
int dx[8] = { 0,0,1,-1,1,-1,-1,1 };

void DFS(int xcur, int ycur) {
    // �̹� �湮�� ���̸� Ż��
    if (isVisited[xcur][ycur])
        return;

    // �湮 ǥ��
    isVisited[xcur][ycur] = true;

    // 8������ ���鼭 �밢������ Ȯ��
    for (int i = 0; i < 8; ++i) {
        int nextX = xcur + dx[i];
        int nextY = ycur + dy[i];

        // ���� x, y ��ǥ�� ���� ����
        if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w) {

            // �湮���� �ʾҰ�, ���̸� DFS ����
            if (!isVisited[nextX][nextY] && maps[nextX][nextY]) {
                DFS(nextX, nextY);
            }
        }
    }
}

// �ʱ�ȭ �Լ�
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

    // ������ �Է� �ޱ�
    while (true) {
        cin >> w >> h;

        // 0 0�̸� ����
        if (w == 0 && h == 0)
            break;

        // ������ ��, �ٴ� �Է�
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> maps[i][j];
            }
        }
        // ���� ����
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