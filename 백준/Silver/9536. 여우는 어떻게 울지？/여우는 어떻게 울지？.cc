#include <bits/stdc++.h>
using namespace std;

/*
문자열을 sep로 나눠서 벡터로 반환하는 함수
EX)
s="A1**B1**C1**D1**E1**F1**G1", sep="**" 인 경우
"**"를 제외한 오른쪽 문자열들을 "A1","B1","C1","D1","E1","F1","G1" vector에 집어넣어 해당 vector를 반환
*/
vector<string> split(const string& s, const string& sep) {
    vector<string> ret;
    size_t pos = 0;
    while (pos < s.size()) {
        size_t nxt_pos = s.find(sep, pos);
        if (nxt_pos == string::npos)
            nxt_pos = s.size();
        if (nxt_pos > pos)
            ret.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore(); // t 입력시 버퍼에 남게되는 '\n' 문자 제거

    while (t--) {
        vector<string> allTears;
        vector<string> animalTearsExceptFox;
        vector<string> result;

        // 입력 받은 녹음 결과 문자열을 공백을 기준으로 분할하여 벡터에 저장
        string s;
        getline(cin, s);
        allTears = split(s, " ");

        // 여우의 울음소리를 제외한 동물의 울음소리를 벡터에 저장
        while (1) {
            getline(cin, s);
            if (s == "what does the fox say?") break;
            animalTearsExceptFox.push_back(split(s, " ").back());
        }

        // 동물의 울음소리 중에서 녹음 결과에 없는 소리를 찾아 결과 벡터에 저장
        for (const auto& tear : allTears) {
            bool found = false;
            for (const auto& animalTear : animalTearsExceptFox) {
                if (tear == animalTear) {
                    found = true;
                    break;
                }
            }
            if (!found) result.push_back(tear);
        }

        // 결과 벡터 출력
        for (const auto& str : result) {
            cout << str << ' ';
        }
    }

    return 0;
}