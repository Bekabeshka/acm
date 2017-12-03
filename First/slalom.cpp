#include <iostream>
#include <cmath>
using namespace std;

int a[1001][1001];
int b[1001][1001];

int main(){

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> a[i - 1][j];
			b[i - 1][j] = 0;
		}
	}

	b[0][0] = a[0][0];
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++){
			if (j == 0)
				b[i][j] = b[i - 1][j] + a[i][j];
			else if (i == j)
				b[i][j] = b[i - 1][j - 1] + a[i][j];
			else
				b[i][j] = max(b[i - 1][j], b[i - 1][j - 1]);
		}
	}

	int maxi = -1;
	for (int i = 1; i < n; i++) {
		if (b[n - 1][i] > maxi) {
			maxi = b[n - 1][i];
		}
	}
	cout << maxi;
	return 0;
}

