#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> kid(n);
    for (int i = 0; i < n; i++) {
        cin >> kid[i];
    }
    
    vector<int> diff(n-1);
    for (int i = 0; i < n-1; i++) {
        diff[i] = kid[i + 1] - kid[i];
    }
    
    sort(diff.begin(), diff.end());
    
    long long result = 0;
    for (int i = 0; i < n-k; i++) {
        result += diff[i];
    }
    
    cout << result << "\n";
}