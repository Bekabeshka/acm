#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> u, t;

	string str;
	cin >> str;

	int amount[26];

	for (int i = 0; i < 26; i++) {
		amount[i] = 0;
	}

	for (int i = 0; i < str.length(); i++) {
		amount[str[i] - 97]++;
	}

	int k = 0;
	int i = 0;

	while (i < str.length()) {
		
		if (amount[k] > 0) {
// заполняем t пока не всретим минималный элемент
			while (str[i] != (char)(97 + k) && i < str.length()) {
				amount[str[i] - 97]--;
				t.push(str[i]);
				i++;
			}
// кладем мин. элемент в u 
			if (str[i] == (char)(97 + k) && i < str.length()) {
				u.push(str[i]);
				amount[k]--;
				i++;
			}
		} else {
// находим следущий минимальный эл.
			while (amount[k] == 0 && k < str.length()) {
				k++;
			}

			while (!t.empty() && t.top() <= (97 + k)) {
				u.push(t.top());
				t.pop();
			}

		}
	
	}

	while (!t.empty()) {
		u.push(t.top());
		t.pop();
	}

	string result = "";

	while (!u.empty()) {
		result += u.top();
		u.pop();
	}

	for (int i = result.length() - 1; i > -1; i--) {
		cout << result[i];
	}

	return 0;
}