#include <iostream>
using namespace std;

int *arr = new int[99];
int head = -1, tail = -1;

void pop() {
	if (head < tail) {
		head++;
	}
	else if (head == tail) {
		head = -1;
		tail = -1;
	}
}

void push(int value) {
	if (tail == -1) {
		head++;
		tail++;
		arr[tail] = value;
	}
	else {
		tail++;
		arr[tail] = value;
	}
}

int front() {
	if (tail != 0)
		return arr[head];
	return 0;
}

int main()
{
	int number;
	
	for (int i = 0; i < 5; i++) {
		cin >> number;
		push(number);
	}

	for (int i = 0; i < 5; i++) {
		cout << front() << " ";
		pop();
	}

  return 0;
}

