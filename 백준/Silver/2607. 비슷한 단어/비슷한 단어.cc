#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getCount(string s, int count[]){
    for(char c : s){
        count[c-'A']++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    string baseString;
    cin >> baseString;
        
    int baseCount[26] = {0};
    getCount(baseString, baseCount);
    
    int result=0;
    for(int i=0; i<n-1; i++){
        string comparisonString;
        cin >> comparisonString;
        
        int comparisonCount[26] = {0};
        getCount(comparisonString, comparisonCount);
        
        int plusCount = 0;
        int minusCount = 0;
        for(int j=0; j<26; j++){
            if(baseCount[j] > comparisonCount[j]){
                plusCount += baseCount[j]-comparisonCount[j];
            }else if(baseCount[j] < comparisonCount[j]){
                minusCount += comparisonCount[j]-baseCount[j];
            }
        }
        
        if(plusCount <= 1 && minusCount <= 1){
            result++;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}