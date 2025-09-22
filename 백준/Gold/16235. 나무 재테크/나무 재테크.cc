#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m, k;
map<pair<int , int>, vector<int>> trees;
vector<vector<int>> nutritions;
vector<vector<int>> nutritions_tmp;
vector<vector<int>> a;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

void init(){
    cin >> n >> m >> k;
    
    nutritions.resize(n);
    nutritions_tmp.resize(n);
    a.resize(n);
    
    for(int i = 0; i < n; i++){
        nutritions[i].resize(n);
        nutritions_tmp[i].resize(n);
        for(int j = 0; j < n; j++){
            nutritions[i][j] = 5;
        }
    }
    
    for(int i = 0; i < n; i++){
        a[i].resize(n);
        
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    int x, y, z;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        trees[{x-1, y-1}].push_back(z);
    }
}

bool check(int y, int x){
    if(y < 0 || x < 0 || y >= n || x >= n)
        return false;
    return true;
}

void tree_grow(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            nutritions_tmp[i][j] = 0;
        }
    }
    
    //spring
    for(auto i = trees.begin(); i != trees.end(); i++){
        int y = i->first.first;
        int x = i->first.second;
        sort(i->second.begin(), i->second.end());
        
        vector<int> tmp;
        int erased = 0;
        for(int j = 0; j < i->second.size(); j++){
            if(nutritions[y][x] >= i->second[j]){
                tmp.push_back(i->second[j] + 1);
                nutritions[y][x] -= i->second[j];
            }
            else{
                erased += i->second[j] / 2;
            }
        }
        
        i->second = tmp;
        nutritions_tmp[y][x] = erased;
    }
    
    //summer
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            nutritions[i][j] += nutritions_tmp[i][j];
        }
    }
}

void tree_breed(){
    map<pair<int , int>, vector<int>> tree_child;
    
    for(auto i = trees.begin(); i != trees.end(); i++){
        int y = i->first.first;
        int x = i->first.second;
        
        for(int j = i->second.size()-1; j >= 0; j--){
            int tree_size = i->second[j];
            
            if(tree_size % 5 != 0)
                continue;
            
            for(int d = 0; d < 8; d++){
                int ny = y + dy[d];
                int nx = x + dx[d];
                
                if(check(ny, nx)){
                    tree_child[{ny, nx}].push_back(1);
                }
            }
        }
    }
    
    for(auto i = tree_child.begin(); i != tree_child.end(); i++){
        int y = i->first.first;
        int x = i->first.second;
        
        for(int j = 0; j < i->second.size(); j++){
            trees[{y, x}].push_back(i->second[j]);
        }
    }
}

void add_nutritions(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            nutritions[i][j] += a[i][j];
        }
    }
}

void solve(){
    for(int i = 0; i < k; i++){
        tree_grow();
        tree_breed();
        add_nutritions();
    }
    
    int res = 0;
    for(auto i = trees.begin(); i != trees.end(); i++){
        res += i->second.size();
    }
    cout << res;
}

int main() {
    init();
    solve();
    return 0;
}