#include <iostream>
using namespace std;

int d[1001][1001];
int INF = 1000000;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int b, e, l;
		cin >> b >> e >> l;

		d[s][e] = l;
		d[e][s] = l;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && d[i][j] == 0)
				d[i][j] = INF;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);	
			}
		}
	}

	int maxi = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
		 	if (d[i][j] != INF) {
				maxi = max(maxi, d[i][j]);
			}
		}
	}  
	cout << maxi;
	
	return 0;
}