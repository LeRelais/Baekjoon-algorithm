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
	int i_testcase, i_input, i_quarter, i_dime, i_nickel, i_penny, count, n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	cin >> i_testcase;

	while (i_testcase > 0) {
		cin >> i_input; 
		while (i_input > 0) {
			if (i_input >= 25) {
				n1 = i_input / 25;
				i_input %= 25;
			}
			else if (10 <= i_input && i_input < 25)
			{
				n2 = i_input / 10;
				i_input %= 10;
			}
			else if (5 <= i_input && i_input < 10) {
				n3 = i_input / 5;
				i_input %= 5;
			}
			else {
				n4 = i_input;
				i_input %= 1;
			}
		}
		cout << n1 << " " << n2 << " " << n3 << " " << n4 << "\n";
		i_testcase--;
		n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	}
}