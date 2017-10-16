#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	stack<char> safe;
	string str;
	cin >> str;

	int a = 0, 
			max = 0, 
			repetition = 1;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			safe.push('(');
			a++;
		} else if (a > 0) {
			safe.pop();
			a++;
		} 

		if (safe.size() == 0 && str[i + 1] != '(') {
			if (a == max && a != 0)
				repetition++;
			else if (a > max) {
				max = a;
				repetition = 1;
			}
			a = 0;
		}
	}

	cout << max << " " << repetition;

	return 0;
}