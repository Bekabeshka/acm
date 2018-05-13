#include <iostream>
using namespace std;

int n, start, dest;
int arr[10000][2];
bool visited[10000];

void dfs(int k, int s) {
	visited[k] = true;

	for (int i = 0; i < n; i++) {
		if (i == k)
			continue;

		if (i == s && arr[k][s] == 1) {
			cout << "found";
			return;
		}

		if (!visited[i] && arr[k][i] == 1) {
			dfs(i, s);
		}
	}

	return;
}

int main() {
	cin >> n ;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			int x, y;
			cin >> x >> y;

			arr[x][y] = 1;
			arr[y][x] = 1;
		}
	}

	cin >> start >> dest;

	dfs(start, dest);
}