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
    q.push(make_pair(xcur, ycur)); // ���� ��ǥ�� ť ��� �߰�
    isVisited[xcur][ycur] = true; // �湮 ǥ��
    dist[xcur][ycur] = 0; // �̵��� Ƚ��

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        // ã������ ���� ������ �����ϸ�
        if (x == ax && y == ay) {
            cout << dist[x][y] << "\n";
            return;
        }

        // ����Ʈ�� �̵��� �� �ִ� 8������ ���
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < length && ny >= 0 && ny < length) {
                if (!isVisited[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1; // ���� �̵� �Ÿ��� +1
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
    // ü������ �� ���� ���� �Է�
    int length;
    cin >> length;

    // ���� ����Ʈ�� ��ġ, �̵��� ��ġ �Է�;
    cin >> sx >> sy;
    cin >> ax >> ay;

    // �̵��� ���� ��ǥ�� 1�� ����
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