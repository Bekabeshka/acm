#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n, m;
int arr[100001];

int upper_bound(int *mas, int value) {
  int l = 0, r = n - 1;

  while (l < r) {
    int m = r - (r - l)/2;
    if (mas[m] <= value)
      l = m;
    else
      r = m - 1;
  }
  return mas[l] == value ? l + 1 : 0;
}

int main(){
  freopen("right.in" , "r", stdin);
  freopen("right.out", "w", stdout);
  cin >> n >> m;
  
  for(int i =0 ; i < n; i++){
    cin >> arr[i];
  }

  for(int i = 0; i < m ; i++){
  	int k;
    cin >> k;

    cout << upper_bound(arr, k) << endl;
  }

  return 0;
}