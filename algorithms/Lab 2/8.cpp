#include <iostream>
using namespace std;

bool visited[1000];
int arr[1000][1000];

bool dfs(int s, int k, int n) {
	visited[k] = true;

	if (k == s) {
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (i == k)
			continue;
		if (arr[k][i] == 1 && !visited[i]) {
			dfs(s, i, n);
		}
	}
	return false;
}

int main() {
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {	
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	int x, y;
	cin >> x >> y;

	if (dfs(y, x, n)) {
		cout << "yes";
	} cout << "no";

	return 0;
}