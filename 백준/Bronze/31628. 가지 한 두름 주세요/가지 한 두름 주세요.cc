#include <iostream>
#include <string>
#include <vector> // vector를 사용하면 N 크기 변경에 용이하지만, 여기선 배열 유지

using namespace std;

// N=10이므로 크기 10x10 배열 선언
string rgbs[10][10]; 

void solve() {
    // 입력: 10x10 격자
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            cin >> rgbs[i][j];
    }
    
    // 1. 행 검사
    for(int i = 0; i < 10; i++){
        // 현재 행의 첫 번째 원소를 기준 색상으로 설정
        string target_color = rgbs[i][0]; 
        bool is_row_uniform = true;
        
        for(int j = 1; j < 10; j++){ // 두 번째 원소(j=1)부터 끝까지 비교
            if(target_color != rgbs[i][j]){
                is_row_uniform = false; // 일치하지 않으면 false로 설정
                break; // 이 행은 실패했으므로 다음 행으로 이동
            }
        }
        
        // 행 검사 성공: 완전한 행을 찾았으므로 즉시 1을 출력하고 종료
        if(is_row_uniform){
            cout << 1 << endl;
            return;
        }
    }
    
    // 2. 열 검사
    for(int j = 0; j < 10; j++){ // j: 열 인덱스
        // 현재 열의 첫 번째 원소(0행, j열)를 기준 색상으로 설정
        string target_color = rgbs[0][j]; 
        bool is_col_uniform = true;
        
        for(int i = 1; i < 10; i++){ // 두 번째 원소(i=1)부터 끝까지 비교
            // j번째 열의 i번째 원소와 기준 색상 비교
            if(target_color != rgbs[i][j]){ 
                is_col_uniform = false; // 일치하지 않으면 false로 설정
                break; // 이 열은 실패했으므로 다음 열로 이동
            }
        }
        
        // 열 검사 성공: 완전한 열을 찾았으므로 즉시 1을 출력하고 종료
        if(is_col_uniform){
            cout << 1 << endl;
            return;
        }
    }
    
    // 행/열 검사를 모두 마쳤지만 완전한 행/열을 찾지 못함
    cout << 0 << endl;
}

int main() {
    // 입출력 속도 향상 (백준에서 흔히 사용)
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}