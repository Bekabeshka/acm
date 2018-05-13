#include <iostream>
#include <queue>
using namespace std;

bool used[1000][1000];

int main() {
	int n, m;
	cin >> n >> m;

	char arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (arr[i][j] == '#' && !used[i][j]) {
				cnt++;

				queue <pair<int, int>> q;
				q.push(make_pair(i, j));

				while(!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;

					q.pop();

					for (int i = 0; i < 4; i++) {
						if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && !used[x + dx[i]][y + dy[i]] && arr[x + dx[i]][y + dy[i]] == '#') {
							q.push(make_pair(x + dx[i], y + dy[i]));
							used[x + dx[i]][y + dy[i]] = true;
						}
					}	
				}
			}
		}
	}

	cout << cnt;

	return 0;
}