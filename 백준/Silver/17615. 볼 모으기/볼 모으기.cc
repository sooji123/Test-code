#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s;

int leftMove(char color){
    int bollCount = 0;
    for(char c : s){
        if(c == color){
            bollCount++;
        }
    }
    
    int skip = 0;
    for(int i=0; i<n; i++){
        if(s[i] == color){
            skip++;
        }else{
            break;
        }
    }
    
    return bollCount-skip;
}

int rightMove(char color){
    int bollCount = 0;
    for(char c : s){
        if(c == color){
            bollCount++;
        }
    }
    
    int skip = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i] == color){
            skip++;
        }else{
            break;
        }
    }
    
    return bollCount-skip;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    
    vector<int> results;
    results.push_back(rightMove('B'));
    results.push_back(rightMove('R'));
    results.push_back(leftMove('B'));
    results.push_back(leftMove('R'));
    
    int minCount = results[0];
    for (int i=1; i<4; i++) {
        minCount = min(minCount, results[i]);
    }

    cout << minCount << "\n";
    
    return 0;
}