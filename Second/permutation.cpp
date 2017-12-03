#include <iostream>
using namespace std;

int n;
int x, y;
int arr[1001];
int res[1001][1001];

void mySwap(int a,int b) {
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

void generate(int k) {
	if (k == n) {
		for(int i = 0; i < n; i++) {
			res[x][y] = arr[i] << " ";
			y++;
		}
		x++;
	}
	else { 
		for(int j = k; j < n; j++) {
			mySwap(k, j);
			generate(k + 1);
			mySwap(k, j);
		}
	}
}

int main() {

	cin >> n;

	for(int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	generate(0);

	for (int i = 0; i < n; i++) {
		
	}

	return 0;
}