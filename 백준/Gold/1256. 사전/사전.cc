#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_k = 1000000007;
long long dp[201][201];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    long long k;
    cin >> n >> m >> k;
    
    for(int i=0;i<=200;i++){
        dp[i][0] = 1;
        for(int j=1;j<=i;j++){
            dp[i][j] = min((long long)MAX_k, dp[i-1][j] + dp[i-1][j-1]);
        }
    }
    
    if(dp[n+m][n]<k){
        cout<<-1<<"\n";
        return 0;
    }
    
    string result;
    int len = n+m;
    for(int i=0;i<len;i++){
        if(n>0){
            long long c = dp[n+m-1][n-1];
            
            if(k<=c){
                result += 'a';
                n--;
            }else{
                result += 'z';
                k -= c;
                m--;
            }
        }else{
            result+='z';
            m--;
        }
    }
    cout << result << "\n";
}