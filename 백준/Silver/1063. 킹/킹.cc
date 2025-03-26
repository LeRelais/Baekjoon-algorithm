#include <iostream>
#include <string>

using namespace std;

int board[9][9];
string king_pos, stone_pos;
int n;
int king_x, king_y, stone_x, stone_y;

int main() {
    cin >> king_pos >> stone_pos >> n;
    king_x = king_pos[0]-'A'+1;
    king_y = king_pos[1] - '0';
    stone_x = stone_pos[0] - 'A'+1;
    stone_y = stone_pos[1] - '0';
    
    string dir;
    int dy, dx;
    for(int i = 0; i < n; i++){
        cin >> dir;
        dy = 0;
        dx = 0;
        if(dir.length() == 1){
            if(dir[0] == 'B'){
                dy = -1;
            }
            else if(dir[0] == 'T'){
                dy = 1;
            }
            else if(dir[0] == 'L'){
                dx = -1;
            }
            else if(dir[0] == 'R'){
                dx = 1;
            }
        }
        else{
            if(dir[1] == 'B'){
                dy = -1;
            }
            else{
                dy = 1;
            }
            
            if(dir[0] == 'L'){
                dx = -1;
            }
            else{
                dx = 1;
            }
        }
        
        if(king_x + dx >= 9 || king_y + dy >= 9 || king_x +dx < 1 || king_y + dy < 1){
            continue;
        }
         
        if(king_x +dx == stone_x && king_y + dy == stone_y){
            if(stone_x + dx >= 9 || stone_y + dy >= 9 || stone_x +dx < 1 || stone_y + dy < 1){
                continue;
            }
            stone_x = stone_x + dx;
            stone_y = stone_y + dy;
        }

        king_x = king_x + dx;
        king_y = king_y + dy;
    
        
    }
    
    cout << (char)(king_x-1+'A') << king_y << endl;
    cout << (char)(stone_x-1+'A') << stone_y << endl;
    return 0;
}