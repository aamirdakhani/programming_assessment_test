#include <iostream>
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n{}, a{1000}, c{4}, temp{};
	cin >> n;
	while (c > 0) {
		temp = n / a;
		cout << temp << " * " << a << " = " << temp * a << "\n";
		n %= a;
		a /= 10;
		c--;
	}
}