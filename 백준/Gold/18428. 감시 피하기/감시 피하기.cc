#include <iostream>
#include <vector>

using namespace std;

int n;
char board[7][7];
vector<pair<int, int>> teachers;
bool res_flag = false;

bool is_safe() {
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    for (auto t : teachers) {
        for (int i = 0; i < 4; i++) {
            int ny = t.first + dy[i];
            int nx = t.second + dx[i];

            while (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                if (board[ny][nx] == 'O') break;
                if (board[ny][nx] == 'S') return false;
                ny += dy[i];
                nx += dx[i];
            }
        }
    }
    return true;
}

void make_wall(int cnt, int start_r, int start_c) {
    if (res_flag) return; 

    if (cnt == 3) {
        if (is_safe()) res_flag = true;
        return;
    }

    for (int i = start_r; i < n; i++) {
        int j_start = (i == start_r) ? start_c : 0;
        for (int j = j_start; j < n; j++) {
            if (board[i][j] == 'X') {
                board[i][j] = 'O';
                make_wall(cnt + 1, i, j + 1);
                board[i][j] = 'X';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'T') teachers.push_back({i, j});
        }
    }

    make_wall(0, 0, 0);

    if (res_flag) cout << "YES";
    else cout << "NO";

    return 0;
}