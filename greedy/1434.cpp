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
	int N, M;
	cin >> N >> M;

	int* box = new int[N], *book = new int[M], box_capacity = 0, book_amount = 0;
	for (int i = 0; i < N; i++) {
		cin >> box[i];
		box_capacity += box[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> book[i];
		book_amount += book[i];
	}

	cout << box_capacity - book_amount;
}
