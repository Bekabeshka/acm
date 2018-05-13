#include <iostream>
using namespace std;

const long long N = (int)1e5 + 5; 
long long tree[4 * N][12];
long long arr[100005];

void build(long long node, long long a, long long b, long long len) {
	if (a > b) return;
	if (a == b) {
		for(long long i = 1; i <= len; i++) {
			tree[node][i] = 0;
		}
		return ;
	}
	build(2 * node, a, (a + b)/2, len);
	build(2 * node, (a + b)/2 + 1, b, len);
	for(long long i = 1; i <= len; i++) {
		tree[node][i] = tree[2*node][i] + tree[2*node+1][i];
	}
	return;
}
void update(long long node, long long a, long long b, long long start, long long end, long long len, long long val) {
	if (a > b) return ;
	
	if (b < start || a > end) return;
	if (a >= start && b <= end) {
		tree[node][len] += val;
		return;
	}
	update(2 * node, a, (a + b)/2, start, end, len, val);
	update(2 * node + 1, (a + b)/2 + 1, b, start, end, len, val);
	tree[node][len] = tree[2 * node][len] + tree[2 * node + 1][len];
	return;
}

long long sum(long long node, long long a, long long b, long long start, long long end, long long len) {
	
	if(a > b || b < start || a > end) return 0;
	if(a >= start && b <= end) return tree[node][len];
	return sum(2 * node, a, (a + b)/2, start, end, len) + sum(2 * node + 1, (a + b)/2 + 1, b, start, end,len);
	
}

int main() {
	long long n, k, value;
	cin >> n >> k;
	
	for(long long i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	build(1, 1, n, k);

	for(long long i = 1; i <= n; i++) {
		
		for(long long length = 0; length <= k; length++) {
			value = sum(1, 1, n, 1, arr[i] - 1, length);
			
			if (length == 0) {
				value = 1;
			}
			update(1, 1, n, arr[i], arr[i], length + 1, value);
		}
	}
	cout << tree[1][k + 1];
	return 0;
}