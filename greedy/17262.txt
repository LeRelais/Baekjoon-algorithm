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
#include<math.h>
using namespace std;


int main() {
	int n, s, e, a = 0, leavetime = 100000, intime = 0;
	int arr[100001] = { 0, };
	cin >> n;
	while (n--) {
		cin >> s >> e;
		if (s > intime)
			intime = s;
		if (e < leavetime)
			leavetime = e;
	}

	int gap = intime - leavetime;

	if (gap < 0)
		cout << 0;
	else
		cout << gap;
}