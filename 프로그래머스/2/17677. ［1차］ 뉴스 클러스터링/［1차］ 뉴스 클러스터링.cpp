#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0, denom = 0, nume = 0;
    map<string, int> a, b;
    
    for(int i = 0; i < str1.length()-1; i++){
        string tmp = "";
        
        if(!((str1[i] >= 'A' && str1[i] <= 'Z')|| (str1[i] >= 'a' && str1[i] <= 'z'))) 
            continue;
        if(!((str1[i+1] >= 'A' && str1[i+1] <= 'Z' )|| (str1[i+1] >= 'a' && str1[i+1] <= 'z')))
            continue;
        
        if(str1[i] >= 'A' && str1[i] <= 'Z')
           tmp += (str1[i] - 'A' + 'a');
        else
           tmp += str1[i];   
        
        if(str1[i+1] >= 'A' && str1[i+1] <= 'Z')
           tmp += (str1[i+1] - 'A' + 'a');
        else
           tmp += str1[i+1];   
          
        a[tmp]++;
        nume++;
    }
    
    for(int i = 0; i < str2.length()-1; i++){
        string tmp = "";
        
        if(!((str2[i] >= 'A' && str2[i] <= 'Z')|| (str2[i] >= 'a' && str2[i] <= 'z'))) 
            continue;
        if(!((str2[i+1] >= 'A' && str2[i+1] <= 'Z')|| (str2[i+1] >= 'a' && str2[i+1] <= 'z'))) 
            continue;
        
        if(str2[i] >= 'A' && str2[i] <= 'Z')
           tmp += (str2[i] - 'A' + 'a');
        else
           tmp += str2[i];   
        
        if(str2[i+1] >= 'A' && str2[i+1] <= 'Z')
           tmp += (str2[i+1] - 'A' + 'a');
        else
           tmp += str2[i+1];   
          
        b[tmp]++;
        nume++;
    }
    
    for(auto i = a.begin(); i != a.end(); i++){
        if(b.find(i->first) != b.end()){
            map<string, int>::iterator it = b.find(i->first);
            
            if(i->second == it->second)
                denom += i->second;
            else{
                denom += min(i->second, it->second);
            }
        }
    }
    
    if(denom == 0 && nume == 0){
       answer = 65536;
    }
    else
        answer = (int)(((float)denom / (nume - denom)) * 65536);
    return answer;
}