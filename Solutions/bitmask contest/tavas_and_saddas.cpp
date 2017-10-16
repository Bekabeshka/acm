#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	string number;
	cin >> number;

	int result = 0;

	for (int i = 0; i < number.length(); i++) {
		if (number[i] == '4') {
			result += 1 * pow(2.0, number.length() - 1 - i);
		}
		else {
			result += 2 * pow(2.0, number.length() - 1 - i);
		}
	}

	cout << result;

//	system("pause");
    return 0;
}