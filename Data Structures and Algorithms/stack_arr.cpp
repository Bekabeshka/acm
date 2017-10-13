#include <iostream>
using namespace std;

int *arr = new int[9];
int top = 0;

void push(int value) {
	arr[++top] = value;
}

void pop() {
	if (top != -1)
		top--;
}

int peek() {
	if (top != -1)
		return arr[top];
	return 0;
}

int main()
{
	int number;
	for (int i = 0; i < 4; i++) {
		cin >> number;
		push(number);
	}

	for (int i = 0; i < 4; i++) {
		cout << peek() << " ";
		pop();
	}

  return 0;
}