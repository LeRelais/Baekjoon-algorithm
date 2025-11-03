#include <iostream>

using namespace std;

int n, m;
int graph[501][501];
void init(){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 987654321;
        }
    }
    
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a][b] = 1;
    }
}

void solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(graph[j][i] != 987654321 && graph[i][k] != 987654321)
                    graph[j][k] = 1;
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) { // 각 학생 i에 대해
        int count = 0;
        for (int j = 1; j <= n; j++) { // 다른 모든 학생 j에 대해
            // i -> j로 가는 경로가 있거나 (i가 j보다 크다)
            // j -> i로 가는 경로가 있으면 (i가 j보다 작다)
            if (graph[i][j] < 987654321 || graph[j][i] < 987654321) {
                count++;
            }
    }
    // 나 자신(i) 포함해서 N명 모두와 비교가 가능하면 (N-1명에 대해 비교 완료)
    if (count == n) {
        res++;
    }
}
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}