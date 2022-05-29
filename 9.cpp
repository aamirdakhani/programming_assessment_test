#include <iostream>
#include <cstring>

using namespace std;

void substrptr(char s1[], char s2[]) {
	int s1_size = strlen(s1);
	int s2_size = strlen(s2);
	int match_count{}, flag{}, match_index{};

	for (int i = 0; i < s1_size; i++) {
		for (int j = 0; j < s2_size; j++) {
			if (s2[j] == s1[i]) {
				match_count++;
				i++;
			} else {
				match_count = 0;
				i += j - 1;
				j = s2_size;
			}
		}
		if (match_count == s2_size) {
			match_index = i - match_count;
			i += s2_size - 1;
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		// print match_address
		printf("%u\n", &s1[match_index]);
	} else {
		cout << "NULL" << endl;
	}
}

int main() {
	char* s1 = (char*) "AABAACAADAABAABA";
	char* s2 = (char*) "AABA";
	substrptr(s1, s2);
	return 0;
}