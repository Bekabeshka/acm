#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000];

bool check(int n) {
	int lvl[n];
	int index = 0;
	queue<int> q;

	for (int i = 0; i < n; i++)
		lvl[i] = -1;
	lvl[index] = 0;
	q.push(index);

	while(!q.empty()) {
		int k = q.front();
		q.pop();
		
		for (int i = 0; i < n; i++) {
			if (arr[k][i] == 1) {
				if (lvl[i] == -1) {
					lvl[i] = lvl[k] + 1;
					q.push(i);
				} else if (lvl[k] == lvl[i]) {
					return false;
				}
			} 
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> arr[i][j];
	}

	if(check(n)) 
		cout << "BIPARTITE";
	else cout << "NO PARTITE";

	return 0;
}