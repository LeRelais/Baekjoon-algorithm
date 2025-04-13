#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    map<string, int> players;
    
    int n, size, cnt = 1, res = 0;
    char game_type;
    string player;
    
    cin >> n >> game_type;
    
    for(int i = 0; i < n; i++){
        cin >> player;
        
        size = players.size();
        players.insert(pair<string, int>(player, 1));
        
        if(size != players.size()){
            cnt++;
            
            if(game_type == 'Y'){
                res++;
                cnt = 1;
            }
            else if(game_type == 'F'){
                if(cnt == 3){
                    res++;
                    cnt = 1;
                }
            }
            else if(game_type == 'O'){
                if(cnt == 4){
                    res++;
                    cnt = 1;
                }
            }
        }
    }
    
    cout << res;
    
    return 0;
}