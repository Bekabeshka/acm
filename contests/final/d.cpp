#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int k = 1; k <= t; k++) {

		int n;
		cin >> n;

		string arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		string common = arr[0];

		for (int i = 1; i < n; i++) {

			string line = arr[i].substr(0, min(common.length(), line.length() ) );
			
		 	for (int j = 0; j < line.length(); j++) {
		 		if (line[j] != common[j]) {
		 			common = common.substr(0, j);
		 			break;
		 		}	 			
		 	}
		}

		cout << common.length() * n;
	}

	return 0;
}