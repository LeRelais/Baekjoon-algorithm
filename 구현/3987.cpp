#include <iostream>
#include <string>
#include <cstring>
#include <queue>

#define U 0
#define R 1
#define D 2
#define L 3

using namespace std;

int n, m, pr, pc, flag;
string tmp;
char arr[501][501];
bool visited[501][501][4];
char direction[] = { 'U', 'R', 'D', 'L' };

typedef struct _data {
    int y;
    int x;
    int dir;
    int dist;
} DATA;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int bfs(int start_dir) {
    queue<DATA> q;
    q.push({ pr, pc, start_dir, 1 });
    visited[pr][pc][start_dir] = true;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int dir = q.front().dir;
        int dist = q.front().dist;
        q.pop();

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // cout << ny << ' ' << nx << endl;

        if (ny == pr && nx == pc && dir == start_dir) {
            flag = 1;
            return 9999;
        }

        if (ny >= 1 && ny <= n && nx >= 1 && nx <= m && !visited[ny][nx][dir] && arr[ny][nx] != 'C') {
            visited[ny][nx][dir] = true;
            if (arr[ny][nx] == '/') {
                if (dir == 0) {
                    q.push({ ny, nx, 1, dist + 1 });
                }
                else if (dir == 1) {
                    q.push({ ny, nx, 0, dist + 1 });
                }
                else if (dir == 2) {
                    q.push({ ny, nx, 3, dist + 1 });
                }
                else {
                    q.push({ ny, nx, 2, dist + 1 });
                }
            }
            else if (arr[ny][nx] == '\\') {
                if (dir == 0) {
                    q.push({ ny, nx, 3, dist + 1 });
                }
                else if (dir == 1) {
                    q.push({ ny, nx, 2, dist + 1 });
                }
                else if (dir == 2) {
                    q.push({ ny, nx, 1, dist + 1 });
                }
                else {
                    q.push({ ny, nx, 0, dist + 1 });
                }
            }
            else {
                q.push({ ny, nx, dir, dist + 1 });
            }
        }
        else
            return dist;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> tmp;

        for (int j = 1; j <= tmp.length(); j++) {
            arr[i][j] = tmp[j - 1];
        }
    }

    cin >> pr >> pc;
    int res_dir = 99, fin_res = 0;
    for (int i = 0; i < 4; i++) {
        int res = bfs(i);
        if (res == 9999) {
            res_dir = i;
            break;
        }
        if (res > fin_res) {
            fin_res = res;
            res_dir = i;
        }
        memset(visited, false, sizeof(visited));
    }

    if (flag) {
        cout << direction[res_dir] << '\n' << "Voyager";
    }
    else {
        cout << direction[res_dir] << '\n' << fin_res;
    }

    return 0;
}