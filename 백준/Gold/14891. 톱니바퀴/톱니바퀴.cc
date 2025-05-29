#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm> // for std::max (사용하지 않아도 되지만, 일반적으로 포함)

using namespace std;

// 톱니바퀴 배열을 전역으로 유지
deque<int> cogwheels[4]; 

// rotate_cogwheels 함수는 동일
void rotate_cogwheels(int idx, int dir) {
    if (dir == 1) { // 시계 방향
        int last_pole = cogwheels[idx].back();
        cogwheels[idx].pop_back();
        cogwheels[idx].push_front(last_pole);
    } else { // 반시계 방향
        int first_pole = cogwheels[idx].front();
        cogwheels[idx].pop_front();
        cogwheels[idx].push_back(first_pole);
    }
}

// move 함수는 회전시킬 톱니바퀴의 인덱스와 방향을 매개변수로 받도록 변경
void process_rotation(int start_idx, int start_dir) {
    // 각 톱니바퀴의 최종 회전 방향을 저장
    vector<int> rotation_directions(4, 0); 
    
    // 시작 톱니바퀴의 회전 방향 설정
    rotation_directions[start_idx] = start_dir;

    // 1. 왼쪽 방향으로 전파 확인
    int current_dir = start_dir;
    for (int i = start_idx; i > 0; --i) {
        // 현재 톱니바퀴의 9시 방향 톱니 (idx 6) vs 왼쪽 톱니바퀴의 3시 방향 톱니 (idx 2)
        if (cogwheels[i][6] != cogwheels[i-1][2]) { // 극이 다르면
            current_dir *= -1; // 방향 반전
            rotation_directions[i-1] = current_dir; // 왼쪽 톱니바퀴의 회전 방향 기록
        } else { // 극이 같으면 더 이상 전파 안 됨
            break; 
        }
    }

    // 2. 오른쪽 방향으로 전파 확인
    current_dir = start_dir; // 시작 톱니바퀴의 원래 방향으로 리셋! (매우 중요)
    for (int i = start_idx; i < 3; ++i) { // i는 현재 톱니바퀴의 인덱스, i+1은 오른쪽 톱니바퀴의 인덱스
        // 현재 톱니바퀴의 3시 방향 톱니 (idx 2) vs 오른쪽 톱니바퀴의 9시 방향 톱니 (idx 6)
        if (cogwheels[i][2] != cogwheels[i+1][6]) { // 극이 다르면
            current_dir *= -1; // 방향 반전
            rotation_directions[i+1] = current_dir; // 오른쪽 톱니바퀴의 회전 방향 기록
        } else { // 극이 같으면 더 이상 전파 안 됨
            break;
        }
    }
    
    // 3. 모든 톱니바퀴를 동시에 회전
    for (int i = 0; i < 4; ++i) {
        if (rotation_directions[i] != 0) { // 회전이 필요한 톱니바퀴만
            rotate_cogwheels(i, rotation_directions[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string cogwheel_str; // 각 톱니바퀴의 초기 상태를 문자열로 입력받을 변수
    for(int i = 0; i < 4; i++){
        cin >> cogwheel_str; // 문자열을 입력받음
        for(char c : cogwheel_str){ // 문자열의 각 문자를 deque에 추가
            cogwheels[i].push_back(c - '0'); // '0' 또는 '1' 문자를 int로 변환
        }
    }
    
    int k; // 회전 횟수 k (main 함수 내에서 선언하고 입력받음)
    cin >> k; 
    
    for(int i = 0; i < k; i++){
        int num, dir; // 회전시킬 톱니바퀴 번호와 방향 (main 함수 내에서 선언하고 입력받음)
        cin >> num >> dir;
        // 톱니바퀴 번호는 1~4이므로, 인덱스 0~3으로 조정하여 함수 호출
        process_rotation(num - 1, dir); 
    }
    
    int total_score = 0; // 총 점수
    // 점수 계산 (12시 방향 톱니바퀴는 항상 인덱스 0)
    if(cogwheels[0][0] == 1) total_score += 1;   // 1번 톱니 S극이면 1점
    if(cogwheels[1][0] == 1) total_score += 2;   // 2번 톱니 S극이면 2점
    if(cogwheels[2][0] == 1) total_score += 4;   // 3번 톱니 S극이면 4점
    if(cogwheels[3][0] == 1) total_score += 8;   // 4번 톱니 S극이면 8점
    
    cout << total_score << '\n'; // 최종 점수 출력 (줄바꿈 포함)
    
    return 0;
}