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
	int n, l;
	cin >> n >> l;
	int* fruit = new int[n];
	for (int i = 0; i < n; i++)
		cin >> fruit[i];

	sort(fruit, fruit + n);

	for (int i = 0; i < n; i++) {
		if (l >= fruit[i]) {
			l++;
		}
	}
	cout << l;
}