#include <iostream>
#include <queue>

using namespace std;

int n, m, t;
float arr[1001][3003];
int color[1001][1001], visited[1001][1001];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void bfs(int col, int row) {
    queue<pair<int, int>> q;
    q.push({ col, row });

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 1 && ny <= n && nx >= 1 && nx <= m) {
                if (!visited[ny][nx] && color[ny][nx] == 255) {
                    visited[ny][nx] = 1;
                    q.push({ ny, nx });
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m * 3; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> t;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        cnt = 1;
        for (int j = 1; j <= m * 3; j += 3) {
            float avg = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2]) / 3;
            if (avg >= t) {
                color[i][cnt] = 255;
            }
            else
                color[i][cnt] = 0;
            cnt++;
        }
    }

    //   for(int i = 1; i <= n; i++){
    //       for(int j = 1; j <= n; j++){
    //           cout << color[i][j] << ' ';
    //       }
    //       cout << endl;
    //   }

    cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && color[i][j] == 255) {
                visited[i][j] = 1;
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}