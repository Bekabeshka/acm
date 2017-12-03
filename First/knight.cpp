#include <iostream>
using namespace std;

int n, m;
int arr[1001][1001];

int main() {

	cin >> n >> m;

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			arr[i][j] = 0;
		}
	}
	
	arr[2][2] = 1;

	for (int i = 2; i <= n + 1; i++) {
		for (int j = 2; j <= m + 1; j++) {
			if (!((i == 2) && (j == 2))) {
				arr[i][j] = arr[i - 1][j - 2] + arr[i - 2][j - 1];
			}
		}
	}
	
	cout << arr[n + 1][m + 1];
	return 0;
}
