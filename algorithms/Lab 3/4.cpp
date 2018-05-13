#include <iostream>
#include <vector>
using namespace std;

int arr[1001][1001];
int d[1001], u[1001], p[1001];
int INF = 1000000;

int main() {
	int n, s, f;
	cin >> n >> s >> f;
	
	s--;
	f--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		d[i] = INF;
	}
	d[s] = 0;

	for (int i = 0; i < n - 1; i++) {
		int v = -1;

		for (int j = 0; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}
		
		if (d[v] == INF)
			break;
		u[v] = true;

		for (int j = 0; j < n; j++) {
			if (arr[v][j] > 0 && 	!u[j]) {
				d[j] = min(d[v] + arr[v][j], d[j]);
				p[j] = v;
			}
		}
	}

	if (d[f] == INF) {
		cout << -1;
	}
	else {
		vector<int> path;
		for (int v=f; v!=s; v=p[v])
			path.push_back (v);
		path.push_back (s);
		for (vector<int>::iterator i = path.begin(); i != path.end(); ++i) { 
			cout << *i + 1 << " ";
		} 
} 

return 0;
}