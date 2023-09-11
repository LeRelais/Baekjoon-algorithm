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
	int n; 
	cin >> n;
	int count = 0;
	
	while (n % 5 != 0) {
		n -= 3;
		count++;

		if (n < 3 && n != 0) {
			cout << -1 << '\n';
			return 0;
		}
	}

	cout << count + n / 5;
	return 0;
}