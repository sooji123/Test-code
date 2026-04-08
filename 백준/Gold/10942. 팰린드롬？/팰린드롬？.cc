#include <iostream>
#include <vector>

using namespace std;

int numbers[2001];
bool dp[2001][2001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> numbers[i];
    }
    
    for (int i=1; i<=n; i++) {
        dp[i][i] = true;
    }
    for (int i=1; i<n; i++) {
        if (numbers[i] == numbers[i+1]){
            dp[i][i+1] = true;
        }
    }
    for (int len=3; len<=n; len++) {
        for (int i=1; i<=n-len+1; i++) {
            int j = i+len-1;
            if (numbers[i] == numbers[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
            }
        }
    }
    
    int m;
    cin >> m;
    
    while(m--){
        int s, e;
        cin >> s >> e;
        
        cout << (dp[s][e] ? 1 : 0) << "\n";
    }
    
    return 0;
}