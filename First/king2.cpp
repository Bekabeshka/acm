#include <iostream>
#include <cmath>
using namespace std;

int a[8][8];
int b[8][8];

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> a[i][j];
			b[i][j] = 0;
		}
	}

	b[7][0] = 0;
	
	for (int i = 6; i >= 0; i--) {
		b[i][0] = a[i][0] + b[i + 1][0];
	}
	for (int j = 1; j < 8; j++) {
		b[7][j] = b[7][j - 1] + a[7][j];
	}
	for (int i = 6; i >= 0; i--) {
		for (int j = 1; j < 8; j++) {
			b[i][j] = a[i][j] + min(b[i + 1][j], min(b[i + 1][j - 1], b[i][j - 1]));
		}
	}
	cout << b[0][7];
}
