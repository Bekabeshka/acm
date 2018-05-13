#include <iostream>
#include <queue>
using namespace std;

int main() {
	short n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	short dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
	short dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

	short lvl[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			lvl[i][j] == -1;
	}

	queue <pair<short,short>> q;
	q.push(make_pair(x1, y1));
	lvl[x1][y1] = 0;

	while(!q.empty()) {

		short x = q.front().first;
		short y = q.front().second;

		q.pop();

		if (x == x2 && y == y2) {
			cout << lvl[x2][y2];
			return 0;
		}

		for (int i = 0; i < 8; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n) {
				lvl[x + dx[i]][y + dy[i]] = lvl[x][y] + 1;
				q.push(make_pair(x + dx[i], y + dy[i]));
			}
		}
	}

	return 0;
}