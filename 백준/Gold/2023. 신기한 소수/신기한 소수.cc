#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int n;
string res;

bool check(int num){
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)
            return false;
    }
    
    return true;
}

void dfs(int num, int depth){
    if(depth == n){
        cout << num << '\n';
        return;
    }
    
    for(int i = 1; i < 10; i++){
        if(check(num * 10 + i)){
            dfs(num * 10 + i, depth+1);
        }
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
}