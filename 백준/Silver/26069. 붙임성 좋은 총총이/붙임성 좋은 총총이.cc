#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, flag = 0;
    cin >> n;
    set<string> se;
    string str1, str2;
    for(int i = 0; i < n; i++){
        cin >> str1 >> str2;
        
        if(str1 == "ChongChong" || str2 == "ChongChong"){
            flag = 1;
            se.insert(str1);
            se.insert(str2);
        }
        
        if(flag){
            if(se.find(str1) != se.end()){
                se.insert(str2);
            }
            if(se.find(str2) != se.end()){
                se.insert(str1);
            }
        }
    }
    
    cout << se.size();
    return 0;
}