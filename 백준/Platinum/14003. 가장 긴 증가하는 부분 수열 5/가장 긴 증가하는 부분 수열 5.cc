#include <iostream>
#include <vector>
using namespace std;

int n, arr[1000001], index[1000001];
vector<int> seq;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
}

void solve(){
    
    for(int i = 1; i <= n; i++){
        if(seq.size() == 0 || arr[i] > seq.back()){
            seq.push_back(arr[i]);
            index[i] = seq.size()-1;
        }
        else{
            int left = 0, right = seq.size()-1;
            while(left < right){
                int mid = (left + right) / 2;
                
                if(seq[mid] >= arr[i]){
                    right = mid;
                }
                else 
                    left = mid + 1;
            }
            seq[left] = arr[i];
            index[i] = left;
        }
    }
    
    cout << seq.size() << '\n';
    int f = seq.size()-1;
    vector<int> answer;
    for(int i = n; i > 0; i--){
        if(index[i] == f){
            f--;
            answer.push_back(arr[i]);
        }
    }
    
    for(int i = answer.size()-1; i >= 0; i--) cout << answer[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin.tie(nullptr); cout.tie(nullptr);
   
    input();
    solve();
}