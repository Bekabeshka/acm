#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int k, r, l;
	cin >> k >> l >> r;
	
	long long ans = 0;
	
	if (r >= 0 && l >= 0) {
		ans = (long long)((r - l) / k);

		if (l % k == 0) {
			cout << ans + 1;
		} else cout << ans;
	}
	else if (r >= 0 && l < 0) {
		l *= -1;
		ans = (long long)((r + l) / k);
		cout << ans + 1;
	} 
	else {
		l *= -1;
		r *= -1;
		ans = (long long)((l - r) / k);

		if (r % k == 0)
			cout << ans + 1;
		else cout << ans;
	}
}