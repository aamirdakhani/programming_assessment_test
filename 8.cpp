#include <iostream>

using namespace std;

int main()
{
	string s, s2;
	char c;
	cin >> s;
	for (int i = 0; i < s.size() && s.size() > 2; i++) {
		c = s[i];
		int count = 0;
		int j = i;
		while (s[j] == c) {
			count++;
			j++;
		}
		if (count >= 3) {
			s.erase(i, count);
		}
		i -= count - 1;
	}
	cout << s << "\n";
	return 0;
}