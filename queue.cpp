#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *next;
};

class Queue
{
public:
	
	void push(int number) {
		if (first == NULL) {
			first = new node;
			first->value = number;
			first->next = cur;
		}
		else {
			struct node *el = new node;
			el = cur;
			el->value = number;
			cur = new node;
			el->next = cur;
		}
	}

	void pop() {
		if (first != NULL && first->next != NULL) {
			first = first->next;
		}
	}

	int front() {
		if (first != NULL) {
			return first->value;
		}
	}

private:
	struct node *first = NULL;
	struct node *cur = new node;
};

int main()
{
	Queue q;

	int *arr = new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		q.push(arr[i]);
	}
		
	for (int i = 0; i < 5; i++) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}