#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<int> st;
    int n = numbers.size();
    vector<int> answer(n, -1);
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && numbers[i] > numbers[st.top()]){
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }
    return answer;
}