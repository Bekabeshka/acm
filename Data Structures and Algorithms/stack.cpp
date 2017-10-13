#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *next;
};

class Stack
{
public:
	void push(int number) {
		if (top == NULL) {
			top = new node;
			top->value = number;
		}
		else {
			struct node *el;
			el = new node;
			el->value = number;
			el->next = top;
			top = el;
		}
	}

	void pop() {
		struct node *el;
		if (top == NULL) {
			cout << "ERROR";
		}
		else {
			el = top;
			top = top->next;
			delete el;
		}
	}

	int peek() {
		if (top == NULL) {
			cout << "Stack is empty" << '\n';
			return 0;
		}
		return top->value;
	}
	
private:
	struct node *top = NULL;
};

int main() {
	Stack s;

	int *arr = new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> *(arr + i);
		s.push(*(arr + i));
	}

	for (int i = 0; i < 5; i++) {
		cout << s.peek() << " ";
		s.pop();
	}

	return 0;
}