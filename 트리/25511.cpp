#include <iostream>
#include <vector>

using namespace std;

int number_point, target;
int parent, child;
vector<int> tree[100001];
int value[100001];
int visited[100001];
int target_depth;

void search(int cur_node, int cur_depth) {
    // cout << cur_node << '\n';
    for (int i = 0; i < tree[cur_node].size(); i++) {
        if (value[tree[cur_node][i]] == target) {
            target_depth = cur_depth;
            // cout << "cur_node : " << cur_node << ' ' << value[tree[cur_node][i]] << endl;
        }
        search(tree[cur_node][i], cur_depth + 1);
    }
}

int main() {
    cin >> number_point >> target;

    for (int i = 0; i < number_point - 1; i++) {
        cin >> parent >> child;
        tree[parent].push_back(child);
    }

    for (int i = 0; i < number_point; i++) {
        cin >> value[i];
    }

    //   for(int i = 0; i < number_point; i++) {
    //     cout << value[i] << ' ';
    // }
    // cout << endl;

    if (value[0] == target)
        cout << 0;
    else {
        //visited[0] = 1;
        search(0, 1);
        cout << target_depth;
    }

}