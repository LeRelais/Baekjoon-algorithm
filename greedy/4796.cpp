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
	int p, l, v;
	int count, days = 0, idx = 1;
	while (true) {
		cin >> l >> p >> v;
		if (p == 0)
			break;
		count = v / p;
		if (v % p > l)
			v = l;
		else
			v = v % p;
		days = count * l + v;
		printf("Case %d: %d\n", idx, days);
		idx++;
	}
}