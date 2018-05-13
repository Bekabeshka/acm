#include <iostream>
using namespace std;

int res, cnt;
int arr[1001][1001];
int visited[1000];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		arr[x][y] = 1;
		arr[y][x] = 1;
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
		if (cnt == 1) {
			res++;
		}
		cnt = 0;
	}

	cout << res;

	return 0;
}
