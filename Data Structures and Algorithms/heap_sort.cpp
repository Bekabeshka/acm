#include <iostream>
using namespace std;

void buildheap(int arr[], int n, int i)
{
	int root = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && arr[left] > arr[root]) {
		root = left;
	}

	if (right < n && arr[right] > arr[root]) {
		root = right;
	}

	swap(arr[i], arr[root]);

	if (root != i)
	{
		buildheap(arr, n, root);
	}
}

void heapsort(int *arr, int length) {
	for (int i = length / 2 - 1; i >= 0; i--) {
		buildheap(arr, length, i);
	}

	for (int i = length - 1; i > -1; i--)
	{
		swap(arr[0], arr[i]);
		buildheap(arr, i, 0);
	}
}

int main() {

	int arr[6] = {5, 2 , 1, -3, 7, 4};

	heapsort(arr, 6);

	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}