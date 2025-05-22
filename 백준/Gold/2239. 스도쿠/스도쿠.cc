#include <iostream>
#include <string>
#include <vector> // std::vector는 꼭 필요한 것은 아니지만, 명시적으로 포함하는 것이 좋습니다.

using namespace std;

// 스도쿠 보드. col이 행 인덱스, row가 열 인덱스
int sudoku[9][9]; 

// isUsedInRow[행_idx][num]: 해당 행에서 num 숫자가 사용되었는지
bool isUsedInRow[9][10]; 
// isUsedInCol[열_idx][num]: 해당 열에서 num 숫자가 사용되었는지
bool isUsedInCol[9][10]; 
// isUsedInArea[영역_idx][num]: 해당 3x3 영역에서 num 숫자가 사용되었는지
bool isUsedInArea[9][10]; 

// 첫 번째 답을 찾으면 바로 종료하기 위한 플래그
bool found_solution = false;

// (c_idx, r_idx) 좌표가 어떤 3x3 구역에 속하는지 계산하는 함수
// c_idx: 행 인덱스, r_idx: 열 인덱스
int get_area_idx(int c_idx, int r_idx) {
    return (c_idx / 3) * 3 + (r_idx / 3);
}

// 특정 숫자 num을 (c_idx, r_idx) 위치에서 사용/해제하는 함수
// c_idx: 행 인덱스, r_idx: 열 인덱스
void toggle_use(int c_idx, int r_idx, int num, bool use) {
    isUsedInRow[c_idx][num] = use; // c_idx(행)에서 num 사용 여부
    isUsedInCol[r_idx][num] = use; // r_idx(열)에서 num 사용 여부
    isUsedInArea[get_area_idx(c_idx, r_idx)][num] = use; // 해당 3x3 영역에서 num 사용 여부
}

// 스도쿠를 채우는 재귀 함수 (DFS)
// c_idx: 현재 채울 칸의 행 인덱스, r_idx: 현재 채울 칸의 열 인덱스
void fillBlank(int c_idx, int r_idx) {
    // 이미 답을 찾았으면 더 이상 탐색하지 않음
    if (found_solution) {
        return;
    }

    // 현재 칸이 9x9 보드의 마지막 칸을 넘어섰다면 (모든 칸을 채웠다면)
    // col 인덱스 c_idx가 9가 되었다면 모든 행을 처리한 것
    if (c_idx == 9) {
        // 스도쿠 보드 출력
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << sudoku[i][j];
            }
            cout << '\n';
        }
        found_solution = true; // 답을 찾았음을 표시
        return;
    }

    // 다음 칸의 좌표 계산
    int next_c_idx = c_idx;
    int next_r_idx = r_idx + 1;
    if (next_r_idx == 9) { // 현재 열 인덱스가 8(마지막 열)이었다면 다음 행의 첫 칸으로 이동
        next_c_idx = c_idx + 1; // 행 인덱스 증가
        next_r_idx = 0;         // 열 인덱스 0으로 리셋
    }

    // 현재 칸이 이미 채워져 있다면 (0이 아니라면) 다음 칸으로 이동
    if (sudoku[c_idx][r_idx] != 0) {
        fillBlank(next_c_idx, next_r_idx);
    }
    // 현재 칸이 비어있다면 (0이라면) 숫자를 채워봄
    else {
        for (int num = 1; num <= 9; ++num) {
            // 해당 숫자를 현재 칸에 놓을 수 있는지 확인
            // c_idx(행)에 num이 없어야 하고, r_idx(열)에 num이 없어야 하며, 해당 3x3 영역에 num이 없어야 함
            if (!isUsedInRow[c_idx][num] && !isUsedInCol[r_idx][num] && !isUsedInArea[get_area_idx(c_idx, r_idx)][num]) {
                // 숫자를 놓음 (사용 표시)
                sudoku[c_idx][r_idx] = num;
                toggle_use(c_idx, r_idx, num, true);

                // 다음 칸 탐색
                fillBlank(next_c_idx, next_r_idx);

                // 답을 찾았으면 백트래킹 중단
                if (found_solution) {
                    return;
                }

                // 백트래킹 (숫자를 다시 0으로 돌려놓고 사용 해제)
                toggle_use(c_idx, r_idx, num, false);
                sudoku[c_idx][r_idx] = 0;
            }
        }
    }
}

int main() {
    // 입출력 속도 향상 (선택 사항이지만 경쟁 프로그래밍에서 유용)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 스도쿠 보드 입력 받기
    for (int i = 0; i < 9; ++i) { // i는 실제 보드의 행 인덱스
        string s;
        cin >> s;
        for (int j = 0; j < 9; ++j) { // j는 실제 보드의 열 인덱스
            sudoku[i][j] = s[j] - '0';
            // 초기 입력된 숫자가 0이 아니라면 사용 표시
            if (sudoku[i][j] != 0) {
                // toggle_use 함수는 (행_idx, 열_idx, num, use) 순서로 인자를 받음
                toggle_use(i, j, sudoku[i][j], true); 
            }
        }
    }

    // 스도쿠 풀이 시작 (0, 0 칸부터)
    // fillBlank 함수는 (행_idx, 열_idx) 순서로 인자를 받음
    fillBlank(0, 0); 

    return 0;
}