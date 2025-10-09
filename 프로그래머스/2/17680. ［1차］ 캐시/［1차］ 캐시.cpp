#include <string>
#include <vector>
#include <map>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    map<string, int> cache;
    deque<string> lru;
    
    for(int i = 0; i < cities.size(); i++){
        string city = cities[i];
        for(int j = 0; j < city.length(); j++){
            if(city[j] >= 'A' && city[j] <= 'Z')
                city[j] = city[j] - 'A' + 'a';
        }
        if(cacheSize != 0){
            if(cache.find(city) == cache.end()){
                string tmp;
                if(lru.size() == cacheSize){
                    tmp = lru.back();
                    lru.pop_back();
                    cache.erase(tmp);
                }
                cache[city] = i;
                lru.push_front(city);
                answer += 5;
            }
            else{
                deque<string> lru_tmp;
                while(!lru.empty() && lru.back() != city){
                    lru_tmp.push_front(lru.back());
                    lru.pop_back();
                }
                
                lru.pop_back();
                
                while(!lru_tmp.empty()){
                    lru.push_back(lru_tmp.front());
                    lru_tmp.pop_front();
                }
                
                lru.push_front(city);
                cache[city] = i;
                answer += 1;
            }
        }
        else{
            answer += 5;
        }
    }
    
    return answer;
}