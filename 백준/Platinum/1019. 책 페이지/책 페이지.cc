#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 각 숫자의 출현 횟수를 저장할 배열
long long counts[10];

// 한 숫자에 대해 각 자릿수를 카운트하는 헬퍼 함수
void calculate(int n, long long p) {
    string s = to_string(n);
    for (char c : s) {
        counts[c - '0'] += p;
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int start = 1;      // 현재 계산할 페이지의 시작 (1부터 시작)
    long long point = 1; // 현재 자릿수의 가중치 (1의 자리: 1, 10의 자리: 10, ...)

    while (start <= N) {
        // 1. start의 1의 자리를 0으로 맞추기 (예: 1 -> 10, 12 -> 20)
        while (start % 10 != 0 && start <= N) {
            calculate(start, point);
            start++;
        }

        // start가 N보다 커지면 루프 종료 (모든 페이지를 처리했음)
        if (start > N) break;

        // 2. N의 1의 자리를 9로 맞추기 (예: 123 -> 129, 119 -> 119)
        while (N % 10 != 9 && start <= N) {
            calculate(N, point);
            N--;
        }

        // 3. 1의 자리가 0~9로 정렬된 구간 처리
        // (start는 0으로 끝나고 N은 9로 끝나는 상태)
        // ex: start=10, N=19. 이 구간은 (19-10+1)/10 = 1 묶음
        // ex: start=10, N=29. 이 구간은 (29-10+1)/10 = 2 묶음
        // 각 묶음은 point(10)에 해당하는 자릿수에서 0~9까지의 숫자가 한번씩 나옴.
        long long num_blocks = (N / 10 - start / 10 + 1); // 현재 구간의 10단위 묶음 수 (ex: 10~19는 1개, 10~29는 2개)
        for (int i = 0; i < 10; ++i) {
            counts[i] += num_blocks * point;
        }

        // 4. 다음 자릿수로 이동
        start /= 10; // start는 10으로 나눔 (ex: 10 -> 1)
        N /= 10;     // N도 10으로 나눔 (ex: 19 -> 1)
        point *= 10; // 자릿수 가중치를 10배 증가 (ex: 1 -> 10)
    }

    // 결과 출력
    for (int i = 0; i < 10; ++i) {
        cout << counts[i] << (i == 9 ? "" : " ");
    }
    cout << '\n';

    return 0;
}