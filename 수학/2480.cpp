#include <iostream>

using namespace std;

bool allsame, twosame, alldif;
int arr[7];

int main() {


	int maxNum = 0, tmp;
	for (int i = 0; i < 3; i++) {
		cin >> tmp;
		if (maxNum < tmp)
			maxNum = tmp;
		arr[tmp]++;
	}

	for (int i = 1; i <= 6; i++) {
		if (arr[i] == 3)
		{
			allsame = true;
			tmp = i;
			break;
		}
		else if (arr[i] == 2) {
			twosame = true;
			tmp = i;
			break;
		}
	}

	if (allsame) {
		cout << 10000 + tmp * 1000;
	}
	else if (twosame) {
		cout << 1000 + tmp * 100;
	}
	else {
		cout << maxNum * 100;
	}
	return 0;
}