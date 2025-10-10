#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

bool isPrime(long long n){
    if(n <= 1)
        return false;
    for(long long i = 2; i * i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

string convert_to_k_base(int n, int k) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    return s;
}

int solution(int n, int k) {
    int count = 0;
    string k_base = convert_to_k_base(n, k);
    string temp = "";

    // 0을 기준으로 문자열 분리
    for (char c : k_base) {
        if (c == '0') {
            if (!temp.empty()) {
                long long num = stoll(temp); // long long으로 변환
                if (isPrime(num)) {
                    count++;
                }
                temp = "";
            }
        } else {
            temp += c;
        }
    }
    
    // 마지막 남은 숫자 처리
    if (!temp.empty()) {
        long long num = stoll(temp);
        if (isPrime(num)) {
            count++;
        }
    }

    return count;
}