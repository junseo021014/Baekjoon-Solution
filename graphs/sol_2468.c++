#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int height, n;
int maps[101][101];
bool isVisited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int xcur, int ycur, int height) {
    // �̹� �湮�� ���̸� ������
    if (isVisited[xcur][ycur])
        return;

    isVisited[xcur][ycur] = true;

    // ������������ �� ĭ�� �̵��ϸ鼭 ���� ���� ã��
    for (int i = 0; i < 4; ++i) {
        int x = xcur + dx[i];
        int y = ycur + dy[i];

        // x��ǥ y ��ǥ ������ maps ������ �۵��ϱ�
        if (x >= 0 && x < n && y >= 0 && y < n) {
            if (!isVisited[x][y] && maps[x][y] > height) {
                DFS(x, y, height);
            }
        }
    }
}

// ���̸��� �ٸ��Ƿ� �湮 �ʱ�ȭ
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

    // ���� �Է¹ޱ�
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maps[i][j];
        }
    }

    max_area = 0;
    height = 100;

    // �ִ� ���� 100���� 1�� ���ҽ�Ű�� ��� ���̽� ��
    while (height >= 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!isVisited[i][j] && maps[i][j] > height) {
                    DFS(i, j, height);
                    cnt++;
                }
            }
        }

        // �ִ� �������� �������� ū ��쿡�� �ʱ�ȭ
        if (max_area < cnt) {
            max_area = cnt;
        }

        // ���� ���缭 �����ϹǷ� cnt, isVisited �ʱ�ȭ
        cnt = 0;
        height--;
        reset();
    }
    cout << max_area;

    return 0;
}