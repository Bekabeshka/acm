#include <iostream>
using namespace std;

int cnt;
int arr[1001][1001];
bool visited[1001];

void dfs(int k, int n) {
	visited[k] = true;
	for (int i = 0; i < n; i++) {
		if (i == k) {
			continue;
		}
		if (arr[k][i] == 1 && !visited[i]) {
			dfs(i, n);
		}
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		arr[x - 1][y - 1] = 1;
		arr[y - 1][x - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visited[j] = false;

		visited[i] = true;

		dfs(0, n);
		
		for (int j = 0; j < n; j++) {
			if (!visited[j]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
