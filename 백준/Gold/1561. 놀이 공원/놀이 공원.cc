#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int m;
    cin >> n >> m;

    vector<int> times(m);
    for (int i = 0; i < m; i++) cin >> times[i];

    long long low = 0, high = 2000000000LL * 30LL; // 넉넉하게 설정
    long long res = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long cnt = m;

        for (int i = 0; i < m; i++) {
            cnt += (mid / times[i]);
            if (cnt >= n) break; 
        }

        if (cnt >= n) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    long long total = m;
    
    if(n <= m){
        cout << n;
        return 0;
    }
    
    for (int i = 0; i < m; i++) {
        total += (res - 1) / times[i];
    }

    for (int i = 0; i < m; i++) {
        if (res % times[i] == 0) { 
            total++;
            if (total == n) {
                cout << i + 1;
                return 0;
            }
        }
    }

    return 0;
}