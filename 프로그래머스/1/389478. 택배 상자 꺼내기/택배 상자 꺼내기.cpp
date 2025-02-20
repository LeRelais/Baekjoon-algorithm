#include <string>
#include <vector>
#include <iostream>

using namespace std;

int box[101][101];

int solution(int n, int w, int num) {
    int answer = 0;
    
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(y % 2 == 0){
            box[y][i%w] = i+1;
        }
        else{
            box[y][w-1-(i%w)] = i+1;
        }
        x++;
        if(x%w == 0)
            y++;
    }
    
    // for(int i = 0; i < (n/w) + 1; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << box[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    int pos_y = (num-1) / w;
    int pos_x;
    if(pos_y % 2 == 0){
        pos_x = (num-1) % w;
    }
    else
        pos_x = w - ((num-1) % w) - 1;
    
    // cout << "pos_y : " << pos_y << ' ' << "pos_x : " << pos_x << endl;
    
    for(int i = pos_y+1; i < (n/w) + 1; i++){
        if(box[i][pos_x])
            answer++;
        else
            break;
    }
    return answer+1;
}