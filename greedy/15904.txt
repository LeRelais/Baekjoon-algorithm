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
	string arr;
	char* pat = new char[1000];
	int idx = 0;
	getline(cin, arr);

	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] == 'U' || arr[i] == 'C' || arr[i] == 'P') {
			pat[idx] = arr[i];
			idx++;
		}
	}

	int j = 0, count = 0;
	char ucpc[5] = { 'U', 'C', 'P', 'C' };

	for (int i = 0; i < strlen(pat); i++) {
		if (count == 4) break;
		if (pat[i] == ucpc[count]) count++;
	}
	if (count == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
	return 0;
}