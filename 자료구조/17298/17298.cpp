#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int arr[1000001];
int nge[1000001];

int main() {
	cin >> n;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	stack<int> s;

	for (int i = n - 1; i >= 0; i--) {
		if (s.empty()) {
			nge[i] = -1;
			s.push(arr[i]);
		}
		else {
			while (!s.empty() && s.top() <= arr[i])
				s.pop();

			if (s.empty())
				nge[i] = -1;
			else
				nge[i] = s.top();

			s.push(arr[i]);
		}
	}

	for (int i = 0; i < n; i++)
		cout << nge[i] << ' ';
	return 0;
}