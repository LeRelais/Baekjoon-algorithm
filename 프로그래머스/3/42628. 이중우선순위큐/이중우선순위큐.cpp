#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for (string op : operations) {
        char cmd = op[0];
        int num = stoi(op.substr(2));

        if (cmd == 'I') {
            ms.insert(num);
        } else {
            if (ms.empty()) continue;

            if (num == 1) {
                // 최댓값 삭제: 마지막 원소의 반복자를 찾아 삭제
                auto it = prev(ms.end());
                ms.erase(it);
            } else {
                // 최솟값 삭제: 첫 번째 원소 삭제
                ms.erase(ms.begin());
            }
        }
    }

    if (ms.empty()) return {0, 0};
    // 최댓값은 end()의 바로 앞, 최솟값은 begin()
    return {*ms.rbegin(), *ms.begin()};
}