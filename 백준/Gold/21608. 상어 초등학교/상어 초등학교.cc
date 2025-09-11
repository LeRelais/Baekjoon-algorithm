#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
map<int, vector<int>> likes;
vector<vector<int>> arr;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

void init(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        arr[i].resize(n, -1);
    }
}

bool check_valid(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < n;
}

void solve(){
    vector<int> student_order(n * n);
    for(int i = 0; i < n*n; i++) {
        cin >> student_order[i];
        likes[student_order[i]].resize(4);
        for(int j = 0; j < 4; j++) {
            cin >> likes[student_order[i]][j];
        }
    }
    
    for(int i = 0; i < n * n; i++){
       int num = student_order[i];
       
       int best_like = -1;
       int best_empty = -1;
       int best_y = -1;
       int best_x = -1;
       
       for(int r = 0; r < n; r++){
           for(int c = 0; c < n; c++){
               if(arr[r][c] == -1){ // 빈칸일 경우에만
                   int current_like_cnt = 0;
                   int current_empty_cnt = 0;
                   
                   for(int dir = 0; dir < 4; dir++){
                       int ny = r + dy[dir];
                       int nx = c + dx[dir];
                       
                       if(check_valid(ny, nx)){
                           if(arr[ny][nx] == -1){
                               current_empty_cnt++;
                           } else {
                               for(int liked_stu : likes[num]){
                                   if(arr[ny][nx] == liked_stu){
                                       current_like_cnt++;
                                       break;
                                   }
                               }
                           }
                       }
                   }
                   
                   if (current_like_cnt > best_like) {
                       best_like = current_like_cnt;
                       best_empty = current_empty_cnt;
                       best_y = r;
                       best_x = c;
                   } else if (current_like_cnt == best_like) {
                       if (current_empty_cnt > best_empty) {
                           best_empty = current_empty_cnt;
                           best_y = r;
                           best_x = c;
                       } else if (current_empty_cnt == best_empty) {
                           if (r < best_y) {
                               best_y = r;
                               best_x = c;
                           } else if (r == best_y) {
                               if (c < best_x) {
                                   best_x = c;
                               }
                           }
                       }
                   }
               }
           }
       }
       
       arr[best_y][best_x] = num;
    }
    
    // 최종 만족도 점수 계산
    long long res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cur_student = arr[i][j];
            int like_count = 0;
            
            for(int dir = 0; dir < 4; dir++){
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                
                if(check_valid(ny, nx)){
                    for(int liked_stu : likes[cur_student]){
                        if(arr[ny][nx] == liked_stu){
                            like_count++;
                        }
                    }
                }
            }
            
            if (like_count == 1) res += 1;
            else if (like_count == 2) res += 10;
            else if (like_count == 3) res += 100;
            else if (like_count == 4) res += 1000;
        }
    }
    
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    solve();
    return 0;
}