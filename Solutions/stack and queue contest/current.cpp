#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> u;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (u.empty() || u.top() != str[i]) {
			u.push(str[i]);
		} else {
			u.pop();
		}
	}

	if (u.empty()) cout << "Yes";
	else cout << "No";

	return 0;
}