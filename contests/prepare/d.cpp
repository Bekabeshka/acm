#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n, a, b;
	cin >> n >> a >> b;

	int cnt = 1, mod = 0;
	mod = n - a;

	if (mod >= a) {
		mod -= a;
	} else {
		cnt++;
		int num = n - a;
		mod = max(mod, num);
	}

	if (mod >= b) {
		mod -= b;
	} else {
		cnt++;
		int num = n - b;
		mod = max(mod, num);
	}

	if (mod >= a) {
		mod -= a;
	} else {
		cnt++;
		int num = n - a;
		mod = max(mod, num);
	}

	if (mod >= a) {
		mod -= a;
	} else {
		cnt++;
		int num = n - a;
		mod = max(mod, num);
	}

	if (mod >= b) {
		mod -= b;
	} else {
		cnt++;
		int num = n - b;
		mod = max(mod, num);
	}

	cout << cnt;

	return 0;
}