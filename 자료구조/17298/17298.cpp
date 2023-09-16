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
		tmp = max(tmp, arr[i]);
	}


	stack<int> s;
	s.push(arr[0]);
	int idx = 0;

	if (tmp == arr[0])
	{
		nge[idx++] = -1;
	}
	for (int i = 1; i < n; i++) {
		if (s.empty())
			s.push(arr[i]);
		else {
			while (!s.empty() && s.top() < arr[i]) {
				nge[idx++] = arr[i];
				s.pop();
			}
			s.push(arr[i]);
		}
	}

	nge[n - 1] = -1;

	for (int i = 0; i < n; i++) {
		cout << nge[i] << ' ';
	}
	return 0;
}