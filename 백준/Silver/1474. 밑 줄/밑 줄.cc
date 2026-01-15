#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> words(N);
    int total_len = 0;
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        total_len += words[i].length();
    }

    int total_blanks = M - total_len; // 총 필요한 밑줄 수
    int gaps = N - 1;                // 단어 사이의 틈새 수
    int base = total_blanks / gaps;  // 기본 밑줄 개수
    int remainder = total_blanks % gaps; // 1개씩 더 나눠줄 개수

    vector<int> underscore_counts(gaps, base);

    // 1단계: 소문자로 시작하는 단어 앞의 틈새에 우선 배분 (앞에서부터)
    for (int i = 1; i < N; i++) {
        if (remainder > 0 && words[i][0] >= 'a' && words[i][0] <= 'z') {
            underscore_counts[i - 1]++;
            remainder--;
        }
    }

    // 2단계: 남은 밑줄은 대문자로 시작하는 단어 앞의 틈새에 배분 (뒤에서부터)
    for (int i = N - 1; i >= 1; i--) {
        if (remainder > 0 && words[i][0] >= 'A' && words[i][0] <= 'Z') {
            underscore_counts[i - 1]++;
            remainder--;
        }
    }

    // 결과 출력
    string result = words[0];
    for (int i = 0; i < gaps; i++) {
        for (int j = 0; j < underscore_counts[i]; j++) result += '_';
        result += words[i + 1];
    }

    cout << result << endl;

    return 0;
}