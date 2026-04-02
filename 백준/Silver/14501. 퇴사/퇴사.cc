#include <iostream>
#include <vector>
#include <algorithm>

struct Work{
    int t, p;
};

int n;
int dp[17];

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    vector<Work> schedule(n);
    
    for(int i=0; i<n; i++){
        cin >> schedule[i].t >> schedule[i].p;
    }
    
    for(int i=n-1; i>=0; i--){
        int endDay = i + schedule[i].t;
        
        if(endDay <= n){
            dp[i] = max(dp[i+1], schedule[i].p+dp[endDay]);
        }else{
            dp[i] = dp[i+1];
        }
    }
    
    cout << dp[0] << "\n";
}