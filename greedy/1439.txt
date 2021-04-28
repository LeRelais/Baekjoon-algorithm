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
	string s;
	int zero = 0, one = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[i + 1]) {
			if (s[i] == '1')
				one++;
			else
				zero++;
		}
	}
	cout << min(one, zero);
}