#include <iostream>
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n{}, c{};
	cin >> n;
	while (n > 0) {
		c++;
		n /= 10;
	}
	cout << c << "\n";
}