#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<cstring>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 10000000 + 1
using namespace std;

int Res(int* arr, int N, int number) {
	int left = 0, right = N - 1;
	while (left <= right) {
		int mid = (right + left) / 2;
		if (arr[mid] == number)
			return 1;
		else if (arr[mid] > number)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}

int main() {
	int N, M, number = 0;

	scanf("%d", &N);

	int* arr = new int[N+1];

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &number);
		printf("%d ", Res(arr, N, number));
	}

	delete[] arr;

	return 0;
}