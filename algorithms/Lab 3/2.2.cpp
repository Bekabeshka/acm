#include <iostream>
using namespace std;

int cnt;
int arr[100][100];
int was[100][100];
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

void print(int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int x, y;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		arr[x - 1][y - 1] = 1;
		arr[y - 1][x - 1] = 1;
	}
	print(n);
	x = 0;
	y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			visited[j] = false;

		

		arr[x][y] = 0;
		arr[y][x] = 0;
		
		print(n);
		
		dfs(0, n);
		
		for (int j = 0; j < n; j++) {
			if (!visited[j]) {
				cnt++;
				break;
			}
		}

		arr[x][y] = 1;
		arr[y][x] = 1;
	}
//	cout << m - cnt;
	return 0;
}