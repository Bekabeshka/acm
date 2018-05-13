#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int d[10001][10001];
std::vector<int> ans;
bool visited[100001];

int color[100001];

void dfs(int k) {
	visited[k] = true;

	for (int i = 0; i < n; i++) {
		if (i == k) 
			continue;

		if (!visited[i] && d[k][i] == 1) {
			dfs(i);
		}
	}
	ans.push_back(k + 1);
}

void topological_sort() {
	for (int i = 0; i < n; i++) {
		if(!visited[i])
			dfs(i);
	}
	reverse(ans.begin(), ans.end());
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		d[a - 1][b - 1] = 1;
	}

	if (isCyclic()) {
		cout << -1;
		return 0;
	}

	topological_sort();

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}