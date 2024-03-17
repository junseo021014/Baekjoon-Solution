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
    queue<pair<int, int>> q; // int�� pair ��ü ť ����
    q.push(make_pair(xcur, ycur)); // ���� x, y ��ǥ�� q�� ��� �߰�
    isVisited[xcur][ycur] = true; // �湮 ǥ��
    dist[xcur][ycur] = 1; // 1�� ���İ� Ƚ��

    // ť�� �� ������
    while (!q.empty()) {
        int x = q.front().first; // �� �� ť���� ù ��° int ��� -> x ��ǥ
        int y = q.front().second; // �� �� ť���� �� ��° int ��� -> y��ǥ

        q.pop(); // ��� ����

        // �������� �� ĭ�� �̵��ϸ� �� ã��
        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            // ���� ������ ����� �����鼭 �湮���� ���� 1�� �� ��ǥ�� ã��
            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                if (!isVisited[nextX][nextY] && maps[nextX][nextY]) {
                    dist[nextX][nextY] = dist[x][y] + 1; // 1�� ���İ� Ƚ���� ���� ��ǥ������ ������ +1
                    q.push(make_pair(nextX, nextY));
                    isVisited[nextX][nextY] = true;
                }
            }
        }
    }

    // ������ n, m ��ǥ������ �Ÿ� ��ȯ
    return dist[n - 1][m - 1];
}

int main() {
    fastio;

    cin >> n >> m;

    // �ʿ� �̷� �Է¹ޱ�
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