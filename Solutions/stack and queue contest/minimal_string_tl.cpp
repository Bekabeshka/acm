#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
void printStack(stack<T> &s)
{
	if (!s.size())
		return;

	T t = s.top();
	s.pop();

	printStack(s);

	std::cout << t;
	s.push(t);
}

int main()
{
	string str;
	cin >> str;

	stack<char> t, u;

	for (int i = 0; i < str.length(); i++) {
		t.push(str[i]);

		char min = str[i];
		for (int j = i; j < str.length(); j++) {
			if (min > str[j]) {
				min = str[j];
			}
		}

		if (str[i] == min) {
			u.push(t.top());
			t.pop();
		}
		
		char mini = str[i + 1];
		for (int k = i + 1; k < str.length(); k++) {
			if (str[k] < mini)
				mini = str[k];
		}
		
		for (int j = 0; j < t.size(); j++) {	

			if (t.top() < mini) {
				u.push(t.top());
				t.pop();
			}
			else break;

		}
	}

	while (!t.empty()) {
		u.push(t.top());
		t.pop();
	}

	printStack(u);

    return 0;
}