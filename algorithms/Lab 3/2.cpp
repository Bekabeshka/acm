#include <iostream>

using namespace std;

int n, m;
int a[100], b[100];
int col[100];
int cnt = 0;
int c[100][100];

bool used[1000];


void dfs(int k){
	used[k] = 1;
	for (int i = 1; i <= n; i++){
		if (c[k][i] == 1 && !used[i]){
			dfs(i);
		}}
	}
	int main(){
		int bridge = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			
			cin >> a[i];
			cin >> b[i];
			
		}
		for(int i = 0; i < m; i++){
			c[a[i]][b[i]] =1;
			c[b[i]][a[i]] =1;
		}
		
		int cnt = 0;

		for(int i = 1; i <=n; i++){
			if(!used[i]){
				cnt++;
				dfs(i);
			}
		}
		int cnt = 0;
		for(int j = 0; j < m; j++){
			c[a[j]][b[j]] =0;
			c[b[j]][a[j]] =0;
			for(int x = 1; x<=n; x++){
				used[x]= 0;
			}
			for(int i = 1; i <=n; i++){
				if(used[i] == 0){
					cnt++;
					dfs(i);
				}
			}
			c[a[j]][b[j]] =1;
			c[b[j]][a[j]] =1;
			
			if(cnt > cnt ){
				bridge++;
			}

			cnt = 0;
			
		}
		cout << m - bridge;
		return 0;
	}               
