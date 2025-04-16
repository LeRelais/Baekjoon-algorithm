#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<pair<int, int>, int> moves; //Dabbaba가 움직일 수 있는 위치, first = y좌표, x = x좌표
vector<pair<int, int>> dabbaba;

int n, k; // n = 체스판의 가로, 세로 크기,     k = Dabbaba의 수
int dy[] = {-2,0,2,0};
int dx[] = {0,2,0,-2};

bool inRange(int y, int x){
    if(y > n || x > n || x <= 0 || y <= 0)
        return false;
    return true;
}

int main() {
    cin >> n >> k;
    
    
    int y, x;   //Dabbaba의 현재 위치
    
    for(int i = 0; i < k; i++){
        cin >> y >> x;
        dabbaba.push_back({y,x});
        
        for(int j = 0; j < 4; j++){
            int ny = y + dy[j];
            int nx = x + dx[j];
            
            if(inRange(ny, nx)){
                //cout << "ny: " << ny << " nx:" << nx << endl;
                moves.insert(pair<pair<int, int>, int>({ny, nx}, 1));
            }
        }
    }
    
    int cnt = 0; //움직일 수 있는 총 위치
    
    for(int i = 0; i < dabbaba.size(); i++){
        moves.erase({dabbaba[i].first, dabbaba[i].second});
    }
    
    cout << moves.size();
    
    return 0;
}