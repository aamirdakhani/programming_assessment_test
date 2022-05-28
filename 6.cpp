#include <iostream>
#include <set>
using namespace std;

int main() {
	set<string>s;
	int n{};
	string name{};
	cin >> n;
	while(n--) {
		cin >> name;
		s.insert(name);
	}
	cout << "\n";
	for(string names:s)
		cout << names << "\n";
}