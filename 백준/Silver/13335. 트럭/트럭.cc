#include <iostream>
#include <vector>
#include <queue>
#include <numeric> 

using namespace std;

void solve() {
    int n, w, L;
    if (!(cin >> n >> w >> L)) return;

    queue<int> truck_queue;
    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        truck_queue.push(weight);
    }

    queue<int> bridge_queue;
    for (int i = 0; i < w; ++i) {
        bridge_queue.push(0); 
    }

    int time = 0;
    long long current_weight = 0;

    while (!truck_queue.empty() || current_weight > 0) {
        time++;
        int outgoing_weight = bridge_queue.front();
        bridge_queue.pop();

        current_weight -= outgoing_weight;

        if (!truck_queue.empty()) {
            int next_truck_weight = truck_queue.front();
            if (current_weight + next_truck_weight <= L) {
                truck_queue.pop();
                bridge_queue.push(next_truck_weight);
                current_weight += next_truck_weight;
            } else {
                bridge_queue.push(0);
            }
        } else {
            bridge_queue.push(0);
        }
    }

    cout << time << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}