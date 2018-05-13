#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;


long long cnt = 0;
long long b[2222], ok;
std::vector<int> v[2222];

void dfs(int k, int cnt) {
  b[k] = cnt % 2 + 1;

  for (auto i:v[k]) { 
    if(!b[i])
      dfs(i, cnt + 1);
    else if((cnt + 1) % 2 + 1 != b[i]) 
      ok = 1;
  } 
}

int main()
{
  long long t;
  cin >> t;

  for (int k = 1; k <= t; k++) {
    int n, m;
    cin >> n >> m;
    
    for(long long i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }

    for(long long i = 1; i <= n; i++)
      if (!b[i]) 
        dfs(i, 0);

    cout << "Scenario #" << k  << ":" << endl;

    if(ok) cout << "Suspicious bugs found!\n";
    else cout << "No suspicious bugs found!\n";
    
    for(long long i = 1; i <= n; i++) b[i] = false;
      for(long long i = 1; i <= n; i++) v[i].clear();
        ok = false;
    }

    return 0;
  }