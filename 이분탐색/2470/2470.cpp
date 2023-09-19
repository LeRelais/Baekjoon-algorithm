#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long best = 2000000001, arr[100001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n); //-99 -2 -1 4 98 

	long long mix = abs(arr[0] + arr[n - 1]);

	int left = 0, right = n - 1;
	int lower = left, higher = right;
	while (left < right) {
		//cout << "LEFT : " << ' ' << left << "    RIGHT : " << ' ' << right << endl; 
		if (mix > abs(arr[left] + arr[right]))
		{
			mix = abs(arr[left] + arr[right]);
			lower = left;
			higher = right;

			if (mix == 0)
				break;
		}
		if (arr[left] + arr[right] < 0)
			left += 1;
		else
			right -= 1;
	}

	cout << arr[lower] << ' ' << arr[higher];
	return 0;
}