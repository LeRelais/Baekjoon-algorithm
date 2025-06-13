#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

int n, m;
char island[53][53];           // 원본 지도
int  island_id[53][53];        // 0: 물 or 미방문, 1…: 섬 번호
int  visited[53][53];
int  parent[2505], height_[2505];
int  island_cnt = 0, maxHeight = 0;

// 8방향 섬 연결용
int dy8[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dx8[] = {  0, 0,-1, 1, -1,  1,-1, 1 };
// 4방향 물 BFS용
int dy4[] = { -1, 1, 0, 0 };
int dx4[] = {  0, 0,-1, 1 };

void numbering(int row, int col) {
    visited[row][col] = 1;
    island_id[row][col] = ++island_cnt;
    queue<pair<int,int>> q;
    q.push({row, col});
    while (!q.empty()) {
        auto [y,x] = q.front(); q.pop();
        for (int d = 0; d < 8; d++) {
            int ny = y + dy8[d], nx = x + dx8[d];
            if (ny<1||ny>n||nx<1||nx>m) continue;
            if (!visited[ny][nx] && island[ny][nx]=='x') {
                visited[ny][nx] = 1;
                island_id[ny][nx] = island_cnt;
                q.push({ny,nx});
            }
        }
    }
}

// 섬 cnt 에 대해 “인접 물”에서만 BFS 돌려 포함 관계(parent) 설정
void checkAroundBFS(int cnt) {
    bool outFlag = false;
    set<int> s;
    static int chk[53][53];
    memset(chk, 0, sizeof(chk));
    queue<pair<int,int>> q;

    // ① 섬 cnt 에 인접한 물 칸(4방향) 수집
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (island_id[y][x] == cnt) {
                for (int d = 0; d < 4; d++) {
                    int ny = y + dy4[d], nx = x + dx4[d];
                    if (ny<1||ny>n||nx<1||nx>m) {
                        outFlag = true;
                    } else if (!chk[ny][nx] && island[ny][nx]=='.') {
                        chk[ny][nx] = 1;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }

    // ② 물 BFS: map 밖으로 나가면 outFlag, 다른 섬 만나면 s.insert
    while (!q.empty() && !outFlag) {
        auto [y,x] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int ny = y + dy4[d], nx = x + dx4[d];
            if (ny<1||ny>n||nx<1||nx>m) {
                outFlag = true;
            } else if (!chk[ny][nx]) {
                if (island[ny][nx]=='.') {
                    chk[ny][nx] = 1;
                    q.push({ny,nx});
                } else {
                    int other = island_id[ny][nx];
                    if (other!=0 && other!=cnt) {
                        s.insert(other);
                    }
                }
            }
        }
    }

    // ③ outFlag==false 이고, 만난 섬이 있으면 부모 설정
    if (!outFlag && !s.empty()) {
        parent[cnt] = *s.begin();
    }
}

void checkAround() {
    // 초기에는 자기 자신을 parent 로 둠
    for (int i = 1; i <= island_cnt; i++) {
        parent[i] = i;
    }
    // 각 섬에 대해 포함 관계 탐색
    for (int i = 1; i <= island_cnt; i++) {
        checkAroundBFS(i);
    }
}

void trace(int cnt, int h) {
    maxHeight = max(maxHeight, height_[cnt]);
    if (cnt == parent[cnt]) return;
    height_[parent[cnt]] = max(height_[parent[cnt]], h + 1);
    trace(parent[cnt], height_[parent[cnt]]);
}

void traceHeight() {
    for (int i = 1; i <= island_cnt; i++) {
        trace(i, height_[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string line; cin >> line;
        for (int j = 1; j <= m; j++) {
            island[i][j] = line[j-1];
        }
    }

    // 1) 섬 번호 매기기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && island[i][j]=='x') {
                numbering(i,j);
            }
        }
    }
    if (island_cnt == 0) {
        cout << -1;
        return 0;
    }

    // 2) 포함 관계 판정
    memset(height_, 0, sizeof(height_));
    checkAround();

    // 3) 높이 계산
    traceHeight();

    // 4) 결과 집계 & 출력
    vector<int> cnt(maxHeight+1);
    for (int i = 1; i <= island_cnt; i++) {
        cnt[height_[i]]++;
    }
    for (int h = 0; h <= maxHeight; h++) {
        cout << cnt[h] << (h<maxHeight?' ':'\n');
    }
    return 0;
}
