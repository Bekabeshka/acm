#include <iostream>
#include <fstream>
using namespace std;

int main() {
	freopen("absum.in", "r", stdin);
	freopen("absum.out", "w", stdout);
	long a, b;
	cin >> a >> b;
	cout << a + b;
	return 0;
}