#include <iostream>
#include <fstream>
using namespace std;

int visited[100000];
int a[10000][10000];

void dfs(int n, int k) {
	visited[k] = 1;
	for (int i = 0; i < n; i++){
		if (i == k){
			continue;
		}
		if (a[k][i] == 1 && visited[i] == 0){
			cout << i << endl;
			dfs(n, i);
		}
	}
	return;
} 

int main() {
	freopen("a.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		visited[i] = 0;
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	dfs(n, 0);
	return 0;
}
