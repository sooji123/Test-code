#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int max_val = 0;
vector<int> numbers(3);

void dfs(long long current_num) {
    if (current_num>n) return;
    
    max_val = max(max_val, (int)current_num);
    
    for (int i=0; i<k; i++) {
        dfs(current_num * 10 + numbers[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    
    for(int i=0; i<k; i++){
        cin >> numbers[i];
    }
    
    for(int i=0; i<k; i++){
        dfs(numbers[i]);
    }
    
    cout << max_val << "\n";
}