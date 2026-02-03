#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> dp(land.size(), vector<int>(land[0].size(), 0));
    for(int i = 0; i < land[0].size(); i++)
        dp[0][i] = land[0][i];
    
    
    for(int i = 1; i < land.size(); i++){
        for(int j = 0; j < land[i].size(); j++){
            for(int k = 0; k < land[i].size(); k++){
                if(j == k)
                    continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + land[i][j]);
            }
        }
    }
    
    // for(int i = 0; i < land.size(); i++){
    //     for(int j = 0; j < land[i].size(); j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for(int i = 0; i < land[0].size(); i++){
        answer = max(answer, dp[land.size()-1][i]);
    }
    return answer;
}