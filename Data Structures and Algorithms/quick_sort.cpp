#include <iostream>
using namespace std;

void quick_sort(int *arr, int left, int right) {

	int i = left, j = right;
	int pivot = arr[left + (rand() % (right - left))];

	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quick_sort(arr, left, j);
	if (right > i)
		quick_sort(arr, i, right);
}

int main() {
	int n;
	cin >> n;

	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}