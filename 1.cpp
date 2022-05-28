#include <iostream>
#include <cmath>
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int i{}, j{}, temp{}, num {10000};
	int c{4};
	cin >> i;
	while (c >= 0) {
		temp = i / num;
		i = i % num;
		if (temp < 9)
			j += (temp + 1) * pow(10, c);
		else
			j += j * 10;
		c--;
		num /= 10;
	}
	cout << j << "\n";
}