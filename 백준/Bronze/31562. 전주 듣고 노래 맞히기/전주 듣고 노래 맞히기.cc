#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, m, t;
map<string, vector<string>> songs;
int main() {
    cin >> n >> m;
    
    string song, tmp;
    char c;
    for(int i = 0; i < n; i++){
        cin >> t >> song;
        tmp = "";
        for(int j = 0; j < 7; j++){
            cin >> c;
            tmp += c;
        }
        string tmp1 = tmp.substr(0,3);
        songs[tmp1].push_back(song);
    }
    
    for(int i = 0; i < m; i++){
       tmp = "";
        for(int j = 0; j < 3; j++){
            cin >> c;
            tmp += c;
        } 
        
        if(songs[tmp].size() == 0){
            cout << "!\n";
        }
        else if(songs[tmp].size() == 1){
            cout << songs[tmp][0] << '\n';
        }
        else{
            cout << "?\n";
        }
    }
    return 0;
}