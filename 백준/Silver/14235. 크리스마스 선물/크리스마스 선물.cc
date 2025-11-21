#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    priority_queue<int> pq;
    
    cin >> n;
    int a, tmp;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a != 0){
            for(int j = 0; j < a; j++){
                cin >> tmp;
                pq.push(tmp);
            }
        }
        else{
            if(pq.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
                
        }
    }
    return 0;
}