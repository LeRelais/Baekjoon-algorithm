#include <iostream>
#include<string.h>
using namespace std;

int main() {
	char arr[100]={0};
	int res = 1;
	cin>>arr;
	for(int i = 0; i <= (strlen(arr)+1)/2; i++){
		if(arr[i] != arr[strlen(arr)-1-i]){
			res = 0;
			break;
		}
		else continue;
	}
	cout<<res;
	return 0;
}