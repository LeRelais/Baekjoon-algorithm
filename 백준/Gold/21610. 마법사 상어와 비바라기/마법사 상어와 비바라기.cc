#include <iostream>
#include <vector>

using namespace std;

int n, m, t = 1, d, s;
vector<vector<int>> basket, used;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

void init(){
    cin >> n >> m;
    basket.resize(n);
    used.resize(n);
    for(int i = 0; i < n; i++){
        basket[i].resize(n);
        used[i].resize(n);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> basket[i][j];
        }
    }
}

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << basket[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool check(int y, int x){
    if(y >= n || x >= n || x < 0 || y < 0)
        return false;
    if(basket[y][x] == 0)
        return false;
    return true;
}

void move_cloud(){
    vector<pair<int, int>> cloud;
    if(t == 1){
        cloud.push_back({n-1, 0});
        cloud.push_back({n-1, 1});
        cloud.push_back({(n-2+n) % n, 0});
        cloud.push_back({(n-2+n) % n, 1});
        
        int s_tmp = s % n;
        
        for(int i = 0; i < cloud.size(); i++){
            //구름 이동
            cloud[i].first = (cloud[i].first + s_tmp * dy[d-1] + n) % n;
            cloud[i].second = (cloud[i].second + s_tmp * dx[d-1] + n) % n;
            
            //구름 위치에 비 내리기
            basket[cloud[i].first][cloud[i].second] += 1;
        }
        
        //구름 위치에서 대각선 체크
        for(int i = 0; i < cloud.size(); i++){
            int y = cloud[i].first;
            int x = cloud[i].second;
            int tmp = 0;
            
            for(int j = 1; j < 8; j += 2){
                int ny = y + dy[j];
                int nx = x + dx[j];
                
                if(check(ny, nx)){
                    tmp++;
                }
            }
            
            basket[y][x] += tmp;
        }
        
        //구름이 있던 자리 마킹
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                used[i][j] = 0;
            }
        }
        for(int i = 0; i < cloud.size(); i++){
            used[cloud[i].first][cloud[i].second] = 1;
        }
    }
    else{
        //구름 만들기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(basket[i][j] >= 2 && !used[i][j]){
                    cloud.push_back({i,j});
                    basket[i][j] -= 2;
                }
            }
        }

        
        int s_tmp = s % n;
        
        for(int i = 0; i < cloud.size(); i++){
            //구름 이동
            cloud[i].first = (cloud[i].first + s_tmp * dy[d-1] + n) % n;
            cloud[i].second = (cloud[i].second + s_tmp * dx[d-1] + n) % n;
            
            
            //구름 위치에 비 내리기
            basket[cloud[i].first][cloud[i].second] += 1;
        }

        
        //구름 위치에서 대각선 체크
        for(int i = 0; i < cloud.size(); i++){
            int y = cloud[i].first;
            int x = cloud[i].second;
            int tmp = 0;
            
            for(int j = 1; j < 8; j += 2){
                int ny = y + dy[j];
                int nx = x + dx[j];
                
                if(check(ny, nx)){
                    tmp++;
                }
            }
            
            basket[y][x] += tmp;
        }
        
        //구름이 있던 자리 마킹
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                used[i][j] = 0;
            }
        }
        for(int i = 0; i < cloud.size(); i++){
            used[cloud[i].first][cloud[i].second] = 1;
        }
        
    }
}


void solve(){
    for(int i = 0; i < m; i++){
        cin >> d >> s;
        move_cloud();
        t++;
    }
    //구름 만들기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(basket[i][j] >= 2 && !used[i][j]){
                basket[i][j] -= 2;
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(basket[i][j])
                res += basket[i][j];
        }
    }
    
    cout << res;
}

int main() {
    init();
    solve();
    return 0;
}