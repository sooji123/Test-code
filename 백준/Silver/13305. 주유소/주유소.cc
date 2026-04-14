#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> dist(n-1);
    vector<long long> oilPrice(n);
    
    for(int i=0; i<n-1; i++){
        cin >> dist[i];
    }
    
    for(int i=0; i<n; i++){
        cin >> oilPrice[i];
    }
    
    long long minPrice = oilPrice[0];
    long long totalPrice = 0;
    
    for(int i=0; i<n-1; i++){
        minPrice = min(minPrice, oilPrice[i]);
        
        totalPrice += minPrice * dist[i];
    }
    
    cout << totalPrice << "\n";
    
    return 0;
}