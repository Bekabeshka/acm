#include <iostream>
using namespace std;

int cnt;
int l[1001];
int arr[1001][1001];
bool visited[1001];

void dfs(int k, int n) {
	visited[k] = true;
	for (int i = 0; i < n; i++) {
		if (i == l[k])
			continue;
		if(arr[k][i] == 1 && !visited[i]) {
			l[i] = k;
			dfs(i, n);
		}
		else if(arr[k][i] == 1 && visited[i]){
			cnt++;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		arr[x - 1][y - 1] = 1;
	}

	dfs(0, n);
	
	if (cnt > 0)
		cout << "CYCLE";
	else cout << "NO CYCLE";
	
	return 0;
}