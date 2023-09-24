#include <iostream>
#include <stack>

using namespace std;

int arr[1000001];
int count[1000001];
int res[1000001];

int n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		count[arr[i]] += 1;
	}

	stack<int> st;
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && (count[arr[st.top()]] < count[arr[i]])) {
			res[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (res[i] == 0)
			cout << -1 << ' ';
		else
			cout << res[i] << ' ';
	}
	return 0;
}