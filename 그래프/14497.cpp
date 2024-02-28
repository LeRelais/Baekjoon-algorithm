#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n, m, x1, y1, x2, y2;
bool visited[301][301];
char arr[301][301];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

typedef struct _data {
    int y;
    int x;
    int count;
} DATA;

int bfs() {
    queue<DATA> q;
    q.push({ x1, y1, 0 });
    visited[x1][y1] = true;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int count = q.front().count;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!visited[ny][nx] && ny >= 1 && nx >= 1 && ny <= n && nx <= m) {
                visited[ny][nx] = true;
                if (arr[ny][nx] == '1') {
                    arr[ny][nx] = '0';
                }
                else if (arr[ny][nx] == '0')
                    q.push({ ny,nx,count });
                else
                    return 1;

            }
        }
    }

    return 0;
}

int main() {
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;

    string tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = tmp[j - 1];
        }
    }

    int ans = 0;
    while (1) {
        ans++;
        memset(visited, false, sizeof(visited));
        int res = bfs();
        //cout << res;
        if (res)
            break;
    }
    cout << ans;
    return 0;
}