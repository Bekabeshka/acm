#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	stack<pair<int,int> > stack;
	
	int head = 1;
		
	for(int i = 0; i < n; i++) {
		
		int value;
		cin >> value;
	
		if (stack.empty()) {
			stack.push(make_pair(value, i));
		} else {
			while (!stack.empty() && value < stack.top().first) {
				head = (head * (i - stack.top().second + 1)) % 1000000007;
				stack.pop();
			}
			stack.push(make_pair(value, i));
		}
	}

	cout << head;
	return 0;
}