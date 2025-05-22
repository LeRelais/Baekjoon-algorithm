#include <iostream>
#include <vector>
#include <algorithm> // for std::rotate

using namespace std;

int n, m, r;
int arr[301][301];

// 하나의 껍질을 회전시키는 함수
void rotate_shell(int start_y, int start_x, int end_y, int end_x, int rotations) {
    // 현재 껍질의 너비와 높이 계산
    int current_n = end_y - start_y + 1;
    int current_m = end_x - start_x + 1;

    // 만약 껍질의 너비나 높이가 1 이하라면 더 이상 회전할 수 없으므로 종료
    if (current_n <= 0 || current_m <= 0) {
        return;
    }
    
    // 회전할 원소들을 임시로 저장할 벡터
    vector<int> shell_elements;

    // 1. 위쪽 가로줄 (왼쪽에서 오른쪽)
    for (int j = start_x; j <= end_x; ++j) {
        shell_elements.push_back(arr[start_y][j]);
    }
    // 2. 오른쪽 세로줄 (위에서 아래) - 시작점 제외
    for (int i = start_y + 1; i <= end_y; ++i) {
        shell_elements.push_back(arr[i][end_x]);
    }
    // 3. 아래쪽 가로줄 (오른쪽에서 왼쪽) - 시작점 제외
    for (int j = end_x - 1; j >= start_x; --j) {
        shell_elements.push_back(arr[end_y][j]);
    }
    // 4. 왼쪽 세로줄 (아래에서 위) - 시작점 제외
    for (int i = end_y - 1; i > start_y; --i) {
        shell_elements.push_back(arr[i][start_x]);
    }

    // 실제 회전 수 계산 (불필요한 회전 방지)
    // 껍질 둘레의 길이만큼 회전하면 제자리로 돌아오므로, 나머지 연산을 사용
    int actual_rotations = rotations % shell_elements.size();

    // 반시계 방향 회전: std::rotate는 범위를 [first, middle)과 [middle, last)로 나눈 후
    // [middle, last) 부분을 [first, ...)로 옮기고, [first, middle) 부분을 그 뒤에 붙입니다.
    // 따라서 반시계 방향으로 k칸 이동시키려면 `begin() + k`를 `middle`로 사용하면 됩니다.
    rotate(shell_elements.begin(), shell_elements.begin() + actual_rotations, shell_elements.end());

    // 회전된 값을 다시 배열에 채우기
    int idx = 0;
    // 1. 위쪽 가로줄 (왼쪽에서 오른쪽)
    for (int j = start_x; j <= end_x; ++j) {
        arr[start_y][j] = shell_elements[idx++];
    }
    // 2. 오른쪽 세로줄 (위에서 아래)
    for (int i = start_y + 1; i <= end_y; ++i) {
        arr[i][end_x] = shell_elements[idx++];
    }
    // 3. 아래쪽 가로줄 (오른쪽에서 왼쪽)
    for (int j = end_x - 1; j >= start_x; --j) {
        arr[end_y][j] = shell_elements[idx++];
    }
    // 4. 왼쪽 세로줄 (아래에서 위)
    for (int i = end_y - 1; i > start_y; --i) {
        arr[i][start_x] = shell_elements[idx++];
    }
}

int main() {
    // 입출력 속도 향상 (선택 사항이지만 경쟁 프로그래밍에서 유용)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    // 껍질별로 회전 수행
    // min(N, M) / 2 만큼 껍질이 존재합니다.
    int num_shells = min(n, m) / 2;

    for (int k = 0; k < num_shells; ++k) {
        // 각 껍질의 시작 (y, x)와 끝 (y, x) 좌표를 계산
        // k는 껍질의 깊이를 나타냅니다 (0은 가장 바깥 껍질, 1은 그 안쪽 껍질 등)
        int start_y = k;
        int start_x = k;
        int end_y = n - 1 - k;
        int end_x = m - 1 - k;

        rotate_shell(start_y, start_x, end_y, end_x, r);
    }

    // 결과 출력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}