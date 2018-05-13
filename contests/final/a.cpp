#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int G[2001][2001];

bool isBipartite(int V, int src);

int main()
{
	int t;
	cin >> t;

	for (int k = 1; k <= t; k++) {
		int n, m;
		cin >> n >> m;

		int arr[m][2];

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			arr[i][0] = a;
			arr[i][1] = b;

			G[a - 1][b - 1] = 1;
		}

		bool bipartite = isBipartite(n, 0);

		for (int i = 0; i < m; i++) {
			G[ arr[i][0] - 1 ][ arr[i][1] - 1 ] = 0;
		}

		cout << "Scenario #" << k << ":" << endl;
		if (bipartite)
			cout << "No suspicious bugs found!\n";
		else cout << "Suspicious bugs found!\n";
	}

	return 0;
}

bool isBipartite(int V, int src)
{
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	colorArr[src] = 1;

	queue <int> q;
	q.push(src);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (G[u][u] == 1)
			return false;  

		for (int v = 0; v < V; ++v)
		{
			if (G[u][v] && colorArr[v] == -1)
			{
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	return true;
}