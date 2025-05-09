#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
string str;
stack<char> s;
 
int main(void) {
    cin >> str;
 
    int answer = 0, temp = 1;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            temp *= 2;
            s.push('(');
        }
        else if(str[i] == '[') {
            temp *= 3;
            s.push('[');
        }
        else if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {   //올바르지 못한 괄호열
                answer = 0;
                break;
            }
            if(str[i-1] == '(') {
                answer += temp;
                temp /= 2;
                s.pop();
            }
            else {
                temp /= 2;
                s.pop();
            }
        }
        else if(str[i] == ']') {
            if(s.empty() || s.top() != '[') {   //올바르지 못한 괄호열
                answer = 0;
                break;
            }
            if(str[i-1] == '[') {
                answer += temp;
                temp /= 3;
                s.pop();
            }
            else {
                temp /= 3;
                s.pop();
            }
        }
    }
 
    if(!s.empty()) answer = 0;  //올바르지 못한 괄호열
 
    cout << answer << "\n";
 
    return 0;
}