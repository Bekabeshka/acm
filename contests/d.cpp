#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main()   
{  
     int a;

     while(cin >> a) {
     	cout << a*a*a*(a*a*a-1)/2-3*a*a*(a-1) << endl;  
     }
     return 0;  
}