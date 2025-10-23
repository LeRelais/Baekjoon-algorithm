#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 8가지 승리 조건 (가로 3, 세로 3, 대각선 2)
int WIN_LINES[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // 가로
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // 세로
    {0, 4, 8}, {2, 4, 6}             // 대각선
};

// 주어진 문자(X 또는 O)가 승리했는지 확인
bool check_win(const string& board, char player) {
    for (int i = 0; i < 8; ++i) {
        if (board[WIN_LINES[i][0]] == player &&
            board[WIN_LINES[i][1]] == player &&
            board[WIN_LINES[i][2]] == player) {
            return true;
        }
    }
    return false;
}

void solve() {
    string str;
    while (cin >> str && str != "end") {
        
        int cnt_x = 0;
        int cnt_o = 0;
        for (char c : str) {
            if (c == 'X') cnt_x++;
            else if (c == 'O') cnt_o++;
        }

        bool x_win = check_win(str, 'X');
        bool o_win = check_win(str, 'O');

        // 1. 말 개수 규칙 확인
        // X는 O와 같거나 하나 더 많아야 합니다. (다른 경우는 즉시 invalid)
        if (cnt_x < cnt_o || cnt_x > cnt_o + 1) {
            cout << "invalid" << '\n';
            continue;
        }

        // 2. 승리 상태에 따른 개수 일관성 확인
        if (x_win && !o_win) {
            // X가 이겼다면: X가 마지막 돌을 놓았어야 함 (X가 O보다 1개 많아야 함)
            if (cnt_x == cnt_o + 1) {
                cout << "valid" << '\n';
            } else {
                cout << "invalid" << '\n'; // X가 이겼는데 X=O인 경우
            }
        } 
        else if (!x_win && o_win) {
            // O가 이겼다면: O가 마지막 돌을 놓았어야 함 (X와 O의 개수가 같아야 함)
            if (cnt_x == cnt_o) {
                cout << "valid" << '\n';
            } else {
                cout << "invalid" << '\n'; // O가 이겼는데 X=O+1인 경우
            }
        } 
        else if (x_win && o_win) {
            // X, O 동시 승리 (불가능)
            cout << "invalid" << '\n';
        }
        else { 
            // 3. 승리자가 없는 경우 (비긴 상태)
            // 비겼다면, 게임판은 반드시 가득 차 있어야만 최종 상태입니다.
            if (cnt_x == 5 && cnt_o == 4) { // 총 9개
                cout << "valid" << '\n';
            } else {
                // 승리자가 없는데 빈 칸이 남아있다면 -> 아직 게임이 끝나지 않은 상태
                cout << "invalid" << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}