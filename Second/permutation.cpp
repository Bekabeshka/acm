#include <iostream>
using namespace std;

int n;
int x, y;
int arr[1001];
int res[1001];

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

void mySwap(int a,int b) {
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

void generate(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			res[y] = arr[i];
			y++;
		}
	}
	else { 
		for (int j = k; j < n; j++) {
			mySwap(k, j);
			generate(k + 1);
			mySwap(k, j);
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	generate(0);

	int size = factorial(n);
	for (int i = 0; i < size * n; i++) {
		cout << res[i] << " ";

		if (i % n == (n - 1))
			cout << '\n';
	}

	return 0;
}