#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int l{}, u{}, flag{};
	vector<int>p{};
	cout << "Enter the lower bound value:\n";
	cin >> l;
	cout << "Enter the upper bound value:\n";
	cin >> u;
	for (int i = l; i <= u; i++) {
		flag = 1;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0)
				flag = 0;
		}
		if (flag == 1)
			p.push_back(i);
	}
	cout << "The prime number between " << l << " and " << u << " are: ";
	for(int x:p)
		cout << x << " ";
	cout << "\n";
}