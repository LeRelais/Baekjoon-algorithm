#include <iostream>
#include <vector>
#include <string>
#include <map> // std::map을 사용하여 TrieNode의 자식들을 관리

using namespace std;

// 트라이 노드 구조체 정의
struct TrieNode {
    map<char, TrieNode*> children; // '0'부터 '9'까지의 숫자를 char로 키로 사용
    bool is_end_of_number;       // 이 노드에서 끝나는 전화번호가 있는지 표시

    TrieNode() : is_end_of_number(false) {}

    // 소멸자: 동적으로 할당된 자식 노드 메모리 해제
    ~TrieNode() {
        for (auto const& pair : children) {
            delete pair.second; // 재귀적으로 자식 노드들 해제
        }
    }
};

// 트라이에 전화번호를 삽입하고 일관성을 검사하는 함수
// 반환값: true (일관성 유지), false (일관성 깨짐)
bool insertAndCheckConsistency(TrieNode* root, const string& phoneNumber) {
    TrieNode* current = root;

    // 전화번호의 각 숫자를 따라 트라이를 탐색하거나 노드를 생성
    for (char digit : phoneNumber) {
        // 1. 현재 노드가 이미 다른 번호의 끝이라면 (예: 911이 있는데 91을 넣으려 함)
        // 현재 번호가 더 긴 번호의 접미어라는 뜻이므로 일관성 없음.
        if (current->is_end_of_number) {
            return false;
        }

        // 해당 숫자에 해당하는 자식 노드가 없으면 새로 생성
        if (current->children.find(digit) == current->children.end()) {
            current->children[digit] = new TrieNode();
        }
        // 다음 노드로 이동
        current = current->children[digit];
    }

    // 2. 전화번호 삽입이 완료된 후, 이 노드가 이미 자식 노드를 가지고 있다면
    // (예: 911을 넣었는데 이미 91125426이 있다면)
    // 방금 삽입한 번호가 다른 더 긴 번호의 접두어라는 뜻이므로 일관성 없음.
    // 또한, 전화번호 길이가 짧더라도, 이 노드가 이미 다른 번호의 끝이라면 (예: 911을 넣었는데 91이 이미 존재했었다면)
    // 위 첫 번째 검사에서 걸러졌을 것이므로 여기서는 `is_end_of_number`만 추가로 확인하면 됩니다.
    if (!current->children.empty()) { // 현재 번호가 다른 더 긴 번호의 접두어인 경우
        return false;
    }
    
    // 현재 노드가 이미 다른 번호의 끝이면서, 방금 넣은 번호가 똑같은 번호였다면
    // 이 문제는 "두 전화번호가 같은 경우는 없다"고 했으므로 이 경우 발생하지 않음.
    // 다만, 논리적으로는 중복 삽입 시 is_end_of_number가 이미 true일 수 있습니다.
    // (문제 조건에 따라 is_end_of_number를 덮어쓰거나, 이미 true이면 무시)
    
    current->is_end_of_number = true; // 현재 번호의 끝을 표시
    return true; // 일관성 유지
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // 테스트 케이스의 개수
    cin >> t;

    while (t--) {
        int n; // 전화번호의 수
        cin >> n;

        // 각 테스트 케이스마다 새로운 트라이 루트 노드 생성
        TrieNode* root = new TrieNode();
        bool is_consistent = true; // 현재 테스트 케이스의 일관성 여부

        // 전화번호들을 입력받고 트라이에 삽입하며 일관성 검사
        for (int i = 0; i < n; ++i) {
            string phoneNumber;
            cin >> phoneNumber;

            // 이미 일관성이 깨졌다면 더 이상 삽입할 필요 없음
            if (!is_consistent) {
                continue;
            }

            // 전화번호를 삽입하고 일관성 검사 결과 반영
            if (!insertAndCheckConsistency(root, phoneNumber)) {
                is_consistent = false;
            }
        }

        // 결과 출력
        if (is_consistent) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        // 현재 테스트 케이스의 트라이 메모리 해제
        delete root;
    }

    return 0;
}