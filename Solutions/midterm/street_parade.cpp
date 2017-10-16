#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

int main () {
	queue<int> crossing;
	stack<int> branch;

	int n;

	string result = "";
	
	while (cin >> n && n != 0) {
		
		bool sorted = true;
		
		for(int i = 0; i < n; i++){
			int value;
			cin >> value;
			crossing.push(value);
		}
		
		int mini = 1;

		while(mini != n){
		
			if (branch.size() != 0 && mini == branch.top()) {
				branch.pop();
				mini++;
				continue;
			} else if (crossing.front() != mini) {
				branch.push(crossing.front());
			} else mini++;
			
			if (!crossing.size() && mini != n) {
				ok = false;
				break;
			}
			
			crossing.pop();
		}

		if (sorted) result += "yes\n";
		else result += "no\n";
	}

	cout << result;
	return 0;
}