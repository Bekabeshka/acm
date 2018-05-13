#include <iostream>
using namespace std;

int n;
int cnt;
int arr[1000][1000];
bool visited[100000];

void dfs(int k) {
	visited[k] = true;
	for (int i = 0; i < n; i++){
		if (i == k) {
			continue;
		}
		if (arr[k][i] == 1 && !visited[i]) {
			dfs(i);
		}
	}
	return;
} 

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; i < n; j++)
			cin >> arr[i][j];
	}

	dfs(0);	

	for (int i = 0; i < n; i++) {
		if (visited[i])
			cnt++;
	}

	cout << cnt;
	return 0;
}