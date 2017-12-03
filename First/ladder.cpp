#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int res[100];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	arr[0] = arr[0];

	res[1] = max(arr[0] + arr[1], arr[1]);

	for (int i = 2; i < n; i++){
		res[i] = max(res[i - 1], res[i - 2]) + arr[i];
	}
	cout << res[n - 1];
}
