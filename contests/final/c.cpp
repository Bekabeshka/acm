#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int a[12],b[12];

int main()
{
    long long t;
    cin >> t;
    for (long long k = 0; k < t; k++) {
        int n;
        cin >> n;
        
        for(int i = 1; i <= n; i++) 
        	cin >> a[i];
        
        b[1] = a[1];
        
        for(long long i=2;i<=n;i++)
        	b[i] = max(b[i - 2] + a[i], b[i - 1]);
	        
		cout << b[n] << endl;
        
        for(long long i = 1; i <= n; i++)
        	b[i]=0;
    }
    return 0;
}