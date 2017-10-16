#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	string arr[n][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
			reverse(arr[i][j].begin(), arr[i][j].end());
		}
	}

	int sum[n];

	for (int i = 0; i < n; i++) {
		sum[i] = stoi(arr[i][0]) + stoi(arr[i][1]);
		string str = to_string(sum[i]);
		reverse(str.begin(), str.end());
		cout << stoi(str) << endl;
	}

	return 0;
}