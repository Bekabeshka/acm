#include <iostream>
#include <string>
#include <stack>
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
	string s;
	cin >> s;

	stack<char> itwas;

	for (int i = 0; i < s.length(); i++) {
		
		if (itwas.empty() || itwas.top() != s[i]) {
			itwas.push(s[i]);
			continue;
		}
		
		if (!itwas.empty()) {
			itwas.pop();
		}
	}

	printStack(itwas);

	return 0;
}