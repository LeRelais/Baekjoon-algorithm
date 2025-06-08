#include <iostream>
#include <map>
#include <string> 

using namespace std;

struct node{
    map<string, node*> leaf;
};

node *ant_hill;
int n;

void print_ant_hill(node *cur, string depth){
    for(auto s : cur->leaf){
        cout << depth << s.first << '\n';
        print_ant_hill(s.second, depth+"--");
    }
}

int main() {
    cin >> n;
    
    string tmp;
    int k;
    ant_hill = new node;
    
    for(int i = 0; i < n; i++){
        node *current_level = ant_hill;
        cin >> k;
        
        for(int j = 0; j < k; j++){
            cin >> tmp;
            
            if(current_level->leaf.find(tmp) == current_level->leaf.end()){
                current_level->leaf[tmp] = new node;
            }
            current_level = current_level->leaf[tmp];
        }
    }
    
    print_ant_hill(ant_hill, "");
    return 0;
}