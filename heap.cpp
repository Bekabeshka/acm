#include <iostream>
using namespace std;

int capacity = 1000;

int *heap = new int[capacity];

int heap_size = 0;
int size;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert_key(int key){
	if (heap_size == capacity){
		cout << "limit capacity" << endl;
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	heap[i] = key;
	while (i!= 0 && heap[ (i -1)/2] > heap[i]){
		swap(&heap[(i-1)/2], &heap[i]);
		i = (i - 1)/2;
	}
}

void minHeaping(int i){
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int smallest = i;
	if (l < heap_size && heap[l] < heap[i]){
		smallest = l;
	}
	if (r < heap_size && heap[r] <  heap[smallest]){
		smallest = r;
	}
	if (smallest != i){
		swap(&heap[i], &heap[smallest]);
		minHeaping(smallest);
	}
	return;
}

void exctractMin() {
	if (heap_size == 0){
		return;
	}
	heap_size--;
	heap[0] = heap[heap_size];
	minHeaping(0);
}

void decrease_key(int i, int new_key) {
	heap[i] = new_key;
	while (i!= 0 && heap[(i-1)/2] > heap[i]) {
		swap(&heap[i], &heap[(i-1)/2]);
		i = (i - 1) / 2;
	}
}

void delete_key(int i){
	decrease_key(i, -30000);
	exctractMin();
}


void print_heap(){
	for (int i = 0; i < heap_size;i++){
		cout << heap[i] << " ";
	}
	cout <<  endl;
}

void print_heap(int size){
	for (int i = 0; i < size;i++){
		cout << heap[i] << " ";
	}
	cout <<  endl;
}

void heapSort() {
	size = heap_size;
	for (int i = 0; i < size; i++) {
		swap(&heap[0], &heap[heap_size - 1 ]);
		heap_size--;
		minHeaping(0);
	}
}

int main() {

	insert_key(10);
	insert_key(15);
	insert_key(30);
	insert_key(40);
	insert_key(50);
	insert_key(100);
	insert_key(40);
	insert_key(13);
	print_heap();

	heapSort();
	print_heap(size);

	system("pause");
	return 0;
} 