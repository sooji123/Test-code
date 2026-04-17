#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    
    vector<int> belt(n);
    for(int i = 0; i < n; i++){
        cin >> belt[i];
    }
    
    for(int i = 0; i < k - 1; i++) {
        belt.push_back(belt[i]);
    }
    
    vector<int> sushi(d+1, 0);
    int uniqueTypes = 0;
        
    for(int i = 0; i < k; i++) {
        if (sushi[belt[i]] == 0) uniqueTypes++;
        sushi[belt[i]]++;
    }
    
    int maxSushi = 0;
    
    for(int i = 0; i < n; i++) {
        int currentTotal = uniqueTypes;
        
        if (sushi[c] == 0){
            currentTotal++;
        }
        
        maxSushi = max(maxSushi, currentTotal);
        
        sushi[belt[i]]--;
        if (sushi[belt[i]] == 0){
            uniqueTypes--;
        }
        
        if (i + k < belt.size()) {
            if (sushi[belt[i + k]] == 0) uniqueTypes++;
            sushi[belt[i + k]]++;
        }
    }
    
    cout << maxSushi << "\n";
    
    return 0;
}