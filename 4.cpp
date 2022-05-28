#include <iostream>
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n{};
    for (int i = 1; i <= 5; i++) {
        int j = 1;
        while (j <= i){
            cout << j << " ";
            j++;
        }
        j = i - 1;
        while (j >= 1) {
            cout << j << " ";
            j--;
        }
        cout << "\n";
    }
}