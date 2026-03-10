#include <iostream>
#include <vector>

using namespace std;

int T;
const int MOD = 1000000009;
const int MAX = 100001;

long long dp[MAX][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[1][1]=1;
    dp[2][2]=1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    
    for (int i = 4; i < MAX; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }
    
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        long long result = (dp[n][1]+dp[n][2]+dp[n][3])%MOD;
        cout << result <<"\n";
    }
    
     return 0;
}