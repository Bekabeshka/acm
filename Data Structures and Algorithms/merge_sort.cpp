#include <iostream>
using namespace std;

void combine(int *arr, int left, int middle, int right) {
	int current = left;

	int n1 = middle - left + 1;
	int n2 = right - middle;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[middle + 1 + i];
	}

	int i = 0, 
			j = 0;

	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			arr[current] = L[i];
			i++;
		} else {
			arr[current] = R[j];
			j++;
		}
		current++;
	}

	while (i < n1) {
		arr[current] = L[i];
		current++;
		i++;
	}
	while (j < n1) {
		arr[current] = R[j];
		current++;
		j++;
	}
}

void merge(int *arr, int left, int right) {
	if (left >= right)
		return;

	int middle = (right + left) / 2;

	merge(arr, left, middle);
	merge(arr, middle + 1, right);

	combine(arr, left, middle, right);
}

int main() {
	int arr[8] = {1, 6, 2, -3, 10, 54, 23, 0};

	merge(arr, 0, 7);

	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}