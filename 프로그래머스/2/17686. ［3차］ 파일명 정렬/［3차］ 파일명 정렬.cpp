#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct DATA {
    string file;
    string head;
    int num;
};

// 정렬 기준
bool cmp(const DATA &a, const DATA &b) {
    if (a.head == b.head) {
        return a.num < b.num;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<DATA> v;

    for (const string& file : files) {
        string head = "";
        string numStr = "";
        int i = 0;

        // 1. HEAD 추출
        while (i < file.length() && !isdigit(file[i])) {
            head += file[i++];
        }

        // 2. NUMBER 추출 (최대 5글자)
        while (i < file.length() && isdigit(file[i]) && numStr.length() < 5) {
            numStr += file[i++];
        }

        // HEAD는 비교를 위해 소문자로 통일
        string lowerHead = head;
        transform(lowerHead.begin(), lowerHead.end(), lowerHead.begin(), ::tolower);

        v.push_back({file, lowerHead, stoi(numStr)});
    }

    // ⭐ 핵심: std::sort 대신 std::stable_sort 사용
    stable_sort(v.begin(), v.end(), cmp);

    for (auto& item : v) {
        answer.push_back(item.file);
    }
    return answer;
}