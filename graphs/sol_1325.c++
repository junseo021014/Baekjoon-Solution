#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

using namespace std;

vector<vector<int>> v;
bool isVisited[10001];
int cnt;
int num = 0;

void dfs(int cur)
{
    if (isVisited[cur])
        return;

    isVisited[cur] = true;

    for (int i = 0; i < v[cur].size(); ++i)
    {
        int next = v[cur][i];

        if (!isVisited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

void findMaxAndIndex(int arr[], int size) {
    // 배열 첫 번째 값으로 max 값 지정
    int max = arr[1];
    int count = 1;  // 최댓값의 갯수
    for (int i = 2; i <= size; ++i) {
        // max값이 갱신될 때마다 count 1로 초기화
        if (arr[i] > max) {
            max = arr[i];
            count = 1;
        }
        // 중복된 최댓값 찾으면 count 증가
        else if (arr[i] == max) {
            count++;
        }
    }

    // 동적할당으로 index 배열 선언
    int* index = new int[count];
    int indexCnt = 0;

    // 최댓값의 인덱스 번호를 index 배열에 저장
    for (int j = 1; j <= size; ++j) {
        if (arr[j] == max) {
            index[indexCnt++] = j;
        }
    }

    // 오름차순으로 인덱스 배열 정렬
    sort(index, index + count);

    // index 배열 출력
    for (int k = 0; k < count; ++k) {
        cout << index[k] << " ";
    }

    // 동적할당 해제
    delete[] index;
}

int main()
{
    fastio;

    int n, m;
    int counter[10001];

    cin >> n >> m;

    v.resize(n + 1);

    // 컴퓨터 신뢰관계 입력
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    // 모든 컴퓨터에 대해 dfs 실행해서 신뢰관계인 컴퓨터 갯수 저장
    for (int i = 1; i <= n; ++i) {
        memset(isVisited, false, n + 1);
        cnt = 1;
        dfs(i);
        counter[i] = cnt;
    }
    
    // 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 넘버 오름차순으로 출력
    findMaxAndIndex(counter, n);

    return 0;
}
