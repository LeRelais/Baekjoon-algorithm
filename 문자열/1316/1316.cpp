#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n;

int main() {
	cin >> n;
	string s;

	int alpha[26], res = 0;
	while (n--) {
		int flag = 0;
		memset(alpha, 0, sizeof(alpha));
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			//cout << s[i];
			if (alpha[s[i] - 'a'] == 0) {
				char cur = s[i];
				while (s[i + 1] == cur) {
					i++;
				}
				alpha[s[i] - 'a'] = 1;
			}
			else {
				flag = 1;
				break;
			}
		}
		//cout << endl;
		if (flag == 0)
			res++;
	}
	cout << res;
}