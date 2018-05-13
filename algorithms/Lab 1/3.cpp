#include <iostream>
using namespace std;

int arr[1000][1000];
bool visited[10000];

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
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int v, u;
	cin >> v >> u;

	dfs(v - 1, n);

	if (visited[u - 1]) {
		cout << "POLTOS";
	} else {
		cout << "DAUREN";
	}

	return 0;
}
