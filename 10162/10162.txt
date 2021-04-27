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
	int T;
	cin >> T;
	int n1 = 0, n2 = 0, n3 = 0, count;
	while (T > 0) {
		if (T >= 300)
		{
			count = T / 300;
			n1+=count;
			T %= 300;
		}
		else if (60 <= T && T < 300) {
			count = T / 60;
			n2 += count;
			T %= 60;
		}
		else
		{
			if (T < 10)
			{
				cout << -1;
				return 0;
			}
			count = T / 10;
			n3 += count;
			T %= 10;
		}
	}
	cout << n1 << " " << n2 << " " << n3;
}