#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int arr[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int a[4] = {-1, 1, 0, 0};
	int b[4] = {0, 0, 1, -1};

	int x, y, dx, dy;
	cin >> y >> x >> dy >> dx;

	queue<pair<int, int>> q;
	
	q.push(make_pair(x, y));
	++arr[x][y];

	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;

		q.pop();

		if (x == dx && y == dy) {
			cout << "YES";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			if (x + a[i] >= 0 && x + a[i] < n && y + b[i] >= 0 && y + b[i] < m && arr[x + a[i]][y + b[i]] == 0) {
				++arr[x + a[i]][y + b[i]];
				q.push(make_pair(x + a[i], y + b[i]));
			}
		}
	}

	cout << "NO";
	return 0;
}