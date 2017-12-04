#include <iostream>
using namespace std;

int n;
int x, y;
int arr[1001];
int b[1001];
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

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	generate(0);

	int size = factorial(n);
	int start = 0;
	int cnt = 0;

	for (int i = 0; i < size * n; i++) {

		if (res[i] == b[cnt]) {
			cnt++;x
		}

		if (cnt == n) {
			start = i / n;
			cout << start;
			break;
		}

		if (i % n == (n - 1)) 
			cnt = 0;

	}
	
	for (int i = start; i < start + n; i++) {
		cout << res[n - i - 1] << " ";
	}
	return 0;
}