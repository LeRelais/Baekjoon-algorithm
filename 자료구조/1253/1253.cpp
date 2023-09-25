#include <iostream>
#include <algorithm>

using namespace std;
long long arr[2001];
int n;
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int res = 0;
	for (int i = 0; i < n; i++) {
		int l = 0, r = n - 1;

		while (l < r) {
			int sum = arr[l] + arr[r];

			if (sum < arr[i]) {
				l++;
			}
			else if (sum > arr[i]) {
				r--;
			}
			else if (sum == arr[i]) {
				if (l != i && r != i) {
					res++;
					break;
				}
				else if (l == i)
					l++;
				else if (r == i)
					r--;
			}
		}
	}
	cout << res;
	return 0;
}