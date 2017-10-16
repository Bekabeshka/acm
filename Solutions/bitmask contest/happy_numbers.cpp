#include <iostream>
#include <string>
using namespace std;

int binpow (int x , int  y) {
  if (y == 0) return 1; 
  if (y % 2 == 1) return binpow (x, y-1) * x; 
  else {
    int b = binpow (x, y/2);
    return b * b;
  }
}

int func(string s){
  int res = 0;
  int i = s.size() - 1;
  int y = 1;
  
  while (i >= 0) {
    res += (s[i] - '0') * y;
    y *=10;
    i--;
  }
  return res;
}

int main() {

  string s;
  cin >> s;   

  int n = func(s);
  int x = s.size();

 `for (int i = 0; i < (1 << s.size()); i++) {

    int sum = 0, z = 0, z1 = 0;
  
    for (int j = 0; j  < x ; ++j) {
      if ((i & (1 << j)) > 0) {
      sum += ((int)(7* binpow(10, j)));
      z++;
      } else {
        sum += ((int)( 4 * binpow(10, j)));
        z1++;
      }
    }

    if (z == z1) {
      if (sum  >= n) {
        cout << sum << endl;
        return 0;
      }
    }
  }

  int r = s.size()+1;

  if (r % 2 == 1) r++; 

  for (int i = 0; i  < (r)/ 2; ++i) {
   cout << 4;
  }

  for (int i = 0; i  < (r)/ 2; ++i) {
   cout << 7;
  }

  return 0;

}