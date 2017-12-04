#include <iostream>
using namespace std;

int n, k;
int arr[100];

void comb(int num) {
	if (num > k) {
		for (int i = 1; i <= k; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	arr[num] = arr[num - 1] + 1;

	while (arr[num] <= n) {
		comb(num + 1);
		arr[num]++;
	}
	return;
}


int main(void) {

	cin >> n >> k;
	
	comb(1);
 
	return 0;
}
