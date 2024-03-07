#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int appeared[201][201][201];
int a, b, c;

typedef struct _data {
    int f;
    int s;
    int t;
} DATA;

queue<DATA> q;
vector<int> v;

void bfs() {
    while (!q.empty()) {
        int f = q.front().f;
        int s = q.front().s;
        int t = q.front().t;
        q.pop();

        if (appeared[f][s][t])
            continue;
        appeared[f][s][t] = 1;
        // cout << f << ' ' << s << ' ' << t << '\n';        
        if (f == 0) {
            v.push_back(t);
        }
        //1번 물통 -> 2번 물통
        if (f + s > b) {
            // f -= (b - s);
            // s = b;
            q.push({ f + s - b, b, t });
        }
        else {
            // s += f;
            // f = 0;
            q.push({ 0, s + f, t });
        }

        //1번 물통 -> 3번 물통
        if (f + t > c) {
            // f -= (c-t);
            // t = c;
            q.push({ f - (c - t), s, c });
        }
        else {
            // t += f;
            // f = 0;
            q.push({ 0, s, t + f });
        }

        //2번 물통 -> 1번 물통
        if (s + f > a) {
            // f = a;
            // s -= (a-f);
            q.push({ a, s - (a - f), t });
        }
        else {
            // f = a;
            // s = 0;
            q.push({ f + s, 0, t });
        }

        //2번 물통 -> 3번 물통
        if (s + t > c) {
            // t = c;
            // s -= (c-t);
            q.push({ f, s - (c - t), c });
        }
        else {
            // t = c;
            // s = 0;
            q.push({ f, 0, t + s });
        }

        //3번 물통 -> 1번 물통
        if (t + f > a) {
            // f = a;
            // t -= (a - f);
            q.push({ a, s, t - (a - f) });
        }
        else {
            // f = a;
            // t = 0;
            q.push({ t + f, s, 0 });
        }

        //3번 물통 -> 2번 물통
        if (t + s > b) {
            // s = b;
            // t -= (b - s);
            q.push({ f, b, t - (b - s) });
        }
        else {
            // s = a;
            // t = 0;
            q.push({ f, s + t, 0 });
        }
    }
}

int main() {
    cin >> a >> b >> c;
    // appeared[0][0][c] = 1;
    q.push({ 0,0, c });
    bfs();

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    return 0;
}