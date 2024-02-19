#include <iostream>
#include <vector>

using namespace std;

int visited[100001];
vector<int> tree[100001];
int apple[100001];
int total;
int point_number, k;

void apple_exist(int cur_node, int cur_dist) {
    if (cur_dist >= k)
        return;
    for (int i = 0; i < tree[cur_node].size(); i++) {
        if (apple[tree[cur_node][i]] == 1) {
            total++;
            //cout << tree[cur_node][i] << ' ' << cur_dist << '\n';
        }
        apple_exist(tree[cur_node][i], cur_dist + 1);
    }
}

int main() {
    cin >> point_number >> k;
    int parent, child;
    for (int i = 0; i < point_number - 1; i++) {
        cin >> parent >> child;
        tree[parent].push_back(child);
    }

    for (int i = 0; i < point_number; i++) {
        cin >> apple[i];
    }

    if (apple[0] == 1)
        total++;

    apple_exist(0, 0);

    cout << total;
    // for(int i = 0; i < point_number; i++){
    //     cout << apple[i];
    // }
    return 0;
}