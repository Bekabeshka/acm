#include <iostream>
using namespace std;

void insertion_sort(int *arr, int length) {
	for (int i = 1; i < length; i++) {
		int k = i;
		for (int j = i - 1; j > -1; j--) {
			if (arr[k] < arr[j]) {
				swap(arr[k],arr[j]);
				k = j;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	insertion_sort(arr, n);

	for (int i = 0; i < n; i++) 
		cout << arr[i] << " ";

	return 0;
}