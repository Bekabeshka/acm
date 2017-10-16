#include <iostream>
#include <stack>
#include <queue> 
using namespace std;

string result = "";

void solutiion(queue<int> crossing, stack<int> branch) {
	int mini = 1;

	while(!crossing.empty()) {
		if (crossing.front() == mini) {
			mini++;
			crossing.pop();
			continue;
		}
		if (branch.top() == mini) {
			mini++;
			branch.pop();
			continue;
		}
		branch.push(crossing.front());
		crossing.pop();
	}
	while(branch.top() == mini){
		mini++;
		branch.pop();
	}

	if (!branch.empty())
		result += "no\n";
	else result += "yes\n";
}

int main() {
	int n;

	queue<int> crossing;
	stack<int> branch;

	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			int number;
			cin >> number;
			crossing.push(number);
		}

		solutiion(crossing, branch);
		
		while (!crossing.empty())
			crossing.pop();
		while (!branch.empty())
			branch.pop();
	}

	cout << result;
	return 0;
}