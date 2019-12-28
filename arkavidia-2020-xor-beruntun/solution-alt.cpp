#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
int arr[MAXN+5], temp[MAXN+5];
int n;

//Tester
int brute(){
	for(int i = 0; i < n; i++){
		temp[i] = arr[i];
	}

	for(int i = n; i >= 1; i--){
		for(int j = 0; j < i-1; j++){
			temp[j] = temp[j]^temp[j+1];
		}
	}
	return temp[0];
}

int calc(){
	if(n == 1){
		return arr[0];
	} else if (n == 2){
		return arr[0]^arr[n-1];
	} else if (n%2){
		return arr[0]^arr[n-1];
	} else {
		return (arr[0]^arr[1]) ^ (arr[n-1]^arr[n-2]);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	printf("%d\n", calc());
}