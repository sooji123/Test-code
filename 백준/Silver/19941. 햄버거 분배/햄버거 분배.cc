#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    string table;
    cin >> table;
    
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (table[i] == 'P') {
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                if (table[j] == 'H') {
                    table[j] = 'X';
                    count++;
                    break;
                }
            }
        }
    }

    cout << count << "\n";
}