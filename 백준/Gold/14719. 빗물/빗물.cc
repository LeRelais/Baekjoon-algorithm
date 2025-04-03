#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<set>
using namespace std;

int h, w, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(nullptr); cout.tie(nullptr);

	stack<int> st;
	cin >> h >> w;

	int l_height = 0;
	while (w--) {
		int h, cnt = 0;
		cin >> h;

		while (!st.empty() && h > st.top()) {
			if (h > l_height && l_height >= st.top()) {
				res += l_height - st.top();
				st.pop();
			}
			else {
				res += h - st.top();
				st.pop();
				cnt++;
			}
		}
		if (cnt) {
			for (int i = 0; i < cnt; i++) {
				st.push(h);
			}
		}

		l_height = max(l_height, h);
		st.push(h);
	}

	cout << res;
}