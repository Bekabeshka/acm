#include <iostream>
#include <vector> 
#include <set> 
using namespace std; 

int n;
bool visited[1000]; 
int arr[1000][1000];

set<int> first; 
set<int> second;

void choose(int k) {
	visited[k] = true;
	first.insert(k + 1);

	for (int i = 0; i < n; i++) {
		if (!visited[i] && arr[k][i] == 1) {
			first.erase(k + 1);
			second.insert(k + 1);
		} 
	}
}

int main() {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && arr[prev][i] == 0) {
			choose(i);
			prev = i;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i])
			first.insert(i + 1);
	}

	for (set<int>::iterator it = first.begin() ; it != first.end(); ++it) { 
		cout << *it <<" "; 
	} cout<< endl; 

	for (set<int>::iterator it = second.begin(); it != second.end(); ++it) { 
		cout << *it <<" "; 
	}

}