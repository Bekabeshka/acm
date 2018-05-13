#include <iostream>
#include <cmath>
using namespace std;

const long long N = (int)1e5 + 7;
int arr[N];
int t[4 * N]; //!! - 4

void build(int v, int tl, int tr) {
	if (tl == tr)
		t[v] = arr[tl];
	else {
		int tm = (tl + tr)/2;
		build(2 * v, tl, tm);
		build(2 * v + 1, tm + 1, tr);
		t[v] = t[2 * v] + t[2 * v + 1];
	}
}

int sum(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (tl == l && tr == r) 
		return t[v];

	int tm = (tl + tr)/2;
	int ch1 = sum(2 * v, tl, tm, l, min(r, tm));
	int ch2 = sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
	return ch1 + ch2;	
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[pos] = new_val;
	else {
		int tm = (tl + tr)/2;
		if (pos <= tm) 
			update(2 * v, tl, tm, pos, new_val);
		else 
			update(2 * v + 1, tm + 1, tr, pos, new_val);

		t[v] = t[2 * v] + t[2 * v + 1];
	}
}

int main() {

	arr[1] = 8;
	arr[2] = 9;
	arr[3] = 10;
	arr[4] = 14;
	arr[5] = 12;
	arr[6] = 7;

	build(1, 1, 6);

	/*for (int i = 1; i <= 6; i++) {
		cout <<	arr[i] << " " << t[i] << endl;
	}

	cout << t[1] << endl << sum(1, 1, 6, 1, 5) << endl;
	
	update(1, 1, 6, 3, 12);
	*/

	for (int i = 1; i <= 6; i++) {
		cout << t[i] << endl;
	}

	cout << endl << t[1] << endl << sum(1, 1, 6, 1, 5);	

	return 0;
}