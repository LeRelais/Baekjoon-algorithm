#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 숫자 하나에 포함된 '9'의 개수를 세는 함수
int countNine(int n) {
    if (n == 0) return 0;
    int cnt = 0;
    while (n > 0) {
        if (n % 10 == 9) cnt++;
        n /= 10;
    }
    return cnt;
}

int rowNine[501];
int colNine[501];

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int totalNine = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            int currentNine = countNine(num);
            
            rowNine[i] += currentNine;
            colNine[j] += currentNine;
            totalNine += currentNine;
        }
    }

    // 행(row)과 열(column) 중에서 9가 가장 많은 줄의 개수 찾기
    int maxNineInLine = 0;
    
    for (int i = 0; i < n; i++) {
        maxNineInLine = max(maxNineInLine, rowNine[i]);
    }
    for (int j = 0; j < m; j++) {
        maxNineInLine = max(maxNineInLine, colNine[j]);
    }

    // 전체 9의 개수 - 가장 많이 지운 줄의 9 개수
    cout << totalNine - maxNineInLine << endl;

    return 0;
}