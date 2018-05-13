#include <iostream>
using namespace std;

long INF = 1000000;

int d[10001];
int arr[101][101];
bool visited[10001];

int main() {

	int n, s, f;
	cin >> n >> s >> f;
	--s;
	--f;
	
	for (int i = 0; i < n; i++) {
		d[i] = INF;
		for (int j = 0; j < n; j++) 
			cin >> arr[i][j];
	}

	d[s] = 0;

	for (int i = 0; i < n - 1; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if ( (v == -1 || d[v] > d[j]) && !visited[j]) {
				v = j;
			}
			
			visited[v] = true;
			if (d[v] == INF)
				break;

			for ()
		}
	}

	if (d[f] != INF)
		cout << d[f];
	else cout << -1;

	return 0;
}