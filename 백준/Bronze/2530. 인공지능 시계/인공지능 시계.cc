#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, m, s, added_t;
    cin >> h >> m >> s >> added_t;
    
    long long total_seconds = (long long)h * 3600 + (long long)m * 60 + s + added_t;

    s = total_seconds % 60;
    long long total_minutes = total_seconds / 60;

    m = total_minutes % 60;
    long long total_hours = total_minutes / 60;
    
    h = total_hours % 24;
    
    cout << h << ' ' << m << ' ' << s << '\n';
    
    return 0;
}