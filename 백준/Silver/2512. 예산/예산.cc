#include <iostream>
#include <vector>

using namespace std;

int n;
int area[10000];
int totalBudget;
int maxBudget = 0;

long long get_total_sum(int limit) {
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        if(area[i] > limit) {
            sum += limit;
        }else{
            sum += area[i];
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> area[i];
        maxBudget = max(maxBudget, area[i]);
    }
    
    cin >> totalBudget;
    
    int left = 0;
    int right = maxBudget;
    int result = 0;
    
    while(left<=right){
        int mid = left + (right-left) / 2;
        
        long long current_sum = get_total_sum(mid);
        
        if(current_sum<=totalBudget){
            result = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    cout << result << "\n";
}