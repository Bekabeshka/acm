#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

map<char, int> one[100001];

int main() 
{
	string text;
	int k = 0;

	getline(cin, text);
	
	do {
		
		for (int i = 97; i < 123; i++) {
			one[k][(char)i] = 0;
		}


		for (int i = 0; i < text.length(); i++) {
			if (text[i] > 96 && text[i] < 123)
				one[k][text[i]] += 1;
		}

		k++;
		getline(cin, text);

	} while (text != "");

	for (int i = 0; i <= k; i++) {
		for (map<char, int>::const_iterator it = one[i].begin(); it!= one[i].end(); it++) {
			cout << it->first << ":" << it->second << endl;
		}
		if (i != k)
			cout << endl;
	}

	return 0;
}