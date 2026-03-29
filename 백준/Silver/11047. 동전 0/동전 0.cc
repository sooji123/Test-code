#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> coins(n);
    
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    
    int result = 0;
    
    for(int i=n-1; i>=0; i--){
        if(k==0){
            break;
        }
        
        if(k>=coins[i]){
            result += k/coins[i];
            k = k%coins[i];
        }
    }
    
    cout << result << "\n";
}