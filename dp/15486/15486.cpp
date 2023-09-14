#include <iostream>

using namespace std;

int t[1500001];
int p[1500001];
int days[1500001];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = n; i >= 1; i--) {
		if (i + t[i] <= n + 1) {
			days[i] = max(days[i + 1], days[i + t[i]] + p[i]);
		}
		else {
			days[i] = days[i + 1];
		}
	}

	//for(int i = 1; i <= n; i++){
	//    cout << days[i] << ' ';
	//}

	cout << days[1];
	return 0;
}