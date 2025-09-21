#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, M, K, r, c, m, s, d;

typedef struct _fireball{
    int r;
    int c;
    int m;
    int s;
    int d;
}FIREBALL;

queue<FIREBALL> fireball;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

void init(){
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        fireball.push({r-1, c-1, m, s, d});
    }
}

void move_fireball(){
    map<pair<int, int>, vector<FIREBALL>> pos; 
    
    while(!fireball.empty()){
        FIREBALL tmp = fireball.front();
        fireball.pop();
        
        r = tmp.r;
        c = tmp.c;
        m = tmp.m;
        s = tmp.s;
        d = tmp.d; 
        
        int s_tmp = s % N;
        
        int nr = (r + dy[d] * s_tmp + N) % N;
        int nc = (c + dx[d] * s_tmp + N) % N;
        
        pos[{nr, nc}].push_back({nr, nc, m, s, d});
    }
    
    for(auto i = pos.begin(); i != pos.end(); i++){
        if(i->second.size() >= 2){
            int r_tmp = i->second[0].d % 2, flag = 1;
            int m_total = i->second[0].m, v_total = i->second[0].s, cnt = i->second.size();
            
            for(int j = 1; j < i->second.size(); j++){
                if(r_tmp != (i->second[j].d % 2))
                {
                    flag = 0;
                }
                m_total += i->second[j].m;
                v_total += i->second[j].s;
            }
            
            if(flag){
                if(m_total / 5 > 0){
                    fireball.push({i->first.first, i->first.second, m_total/5, v_total/cnt, 0});
                    fireball.push({i->first.first, i->first.second, m_total/5, v_total/cnt, 2});
                    fireball.push({i->first.first, i->first.second, m_total/5, v_total/cnt, 4});
                    fireball.push({i->first.first, i->first.second, m_total/5, v_total/cnt, 6});
                }
            }
            else{
                if(m_total / 5 > 0){
                    fireball.push({i->first.first, i->first.second, m_total/5, v_total/cnt, 1});
                    fireball.push({i->first.first, i->first.second, m_total/5, v_total/cnt, 3});
                    fireball.push({i->first.first, i->first.second, m_total/5, v_total/cnt, 5});
                    fireball.push({i->first.first, i->first.second, m_total/5, v_total/cnt, 7});
                }
            }
        }
        else{
            FIREBALL tmp = i->second[0];
            fireball.push(tmp);
        }
    }
}

void solve(){
    for(int i = 0; i < K; i++){
        move_fireball();
    }
    
    int res = 0;
    while(!fireball.empty()){
        res += fireball.front().m;
        fireball.pop();
    }
    cout << res;
}

int main() {
    init();
    solve();
}