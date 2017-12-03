#include <iostream>
using namespace std;

int d[1000][1000];

int main() {
	int n;

	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);	
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}