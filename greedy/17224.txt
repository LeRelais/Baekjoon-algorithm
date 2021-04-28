#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include<map>
#include<algorithm>
#include<string>
#include<queue>
#include <stdio.h>
#include<set>
#include <string.h>
using namespace std;

int main() {
	int n_test, l, num, count2 = 0, count1 = 0;;
	cin >> n_test >> l >> num;

	int *test1 = new int[n_test];
	int *test2 = new int[n_test];
	bool* check = new bool[n_test];
	*check = { false, };

	for (int i = 0; i < n_test; i++) {
		cin >> test1[i] >> test2[i];
	}

	for (int i = 0; i < n_test; i++) {
		if (l >= test2[i]) {
			if (count2 == num)
				break;
			count2++;
			check[i] = true;
		}
	}
	num -= count2;

	for (int i = 0; i < n_test; i++) {
		if (l >= test1[i] && check[i] != true)
			count1++;	
	}
	if (count1 > num)
		count1 = num;

	cout << count2 * 140 + count1 * 100;
}