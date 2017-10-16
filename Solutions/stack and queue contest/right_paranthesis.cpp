#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int result = 0;
	vector<bool> itwas;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			itwas.push_back(true);
			continue;
		}
		if (!itwas.empty()) {
			result += 2;
			itwas.pop_back();
		}
	}

	cout << result;

//	system("pause");
    return 0;
}