#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int f[99999999];

int main()
{
    f[1]=1;
    f[2]=1;
    int a, b, n;
    
    while(true)
    {
    	cin >> a >> b >> n;
    	if(a == 0 && b == 0 && n == 0) break;
        for(int i = 3; i <= 49; i++) {
            f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
        }
        cout << f[n % 49] << endl;
    }
    return 0;
}