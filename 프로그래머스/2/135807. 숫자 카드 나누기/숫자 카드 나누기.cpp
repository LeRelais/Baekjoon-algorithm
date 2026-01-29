#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getGCD(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = arrayA[0];
    
    for(int i = 1; i < arrayA.size(); i++){
        gcdA = getGCD(gcdA, arrayA[i]);
    }
    
    int gcdB = arrayB[0];
    for(int i = 1; i < arrayB.size(); i++){
        gcdB = getGCD(gcdB, arrayB[i]);
    }
    
    bool canB = true;
    for(int i = 0; i < arrayA.size(); i++){
        if(arrayA[i] % gcdB == 0){
            canB = false;
            break;
        }
    }
    
    if(canB)
        answer = max(answer, gcdB);
    
    bool canA = true;
    for(int i = 0; i < arrayB.size(); i++){
        if(arrayB[i] % gcdA == 0){
            canA = false;
            break;
        }
    }
    
    if(canA)
        answer = max(answer, gcdA);
    return answer;
}