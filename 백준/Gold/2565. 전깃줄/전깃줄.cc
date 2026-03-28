#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line{
    int a, b;
};

bool sortLine(Line l1, Line l2){
    return l1.a<l2.a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<Line> lines(n);
    for(int i=0; i<n; i++){
        cin >> lines[i].a >> lines[i].b;
    }
    
    sort(lines.begin(), lines.end(), sortLine);
    
    vector<int> dp(n, 1);
    int maxLines = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(lines[j].b < lines[i].b){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        maxLines = max(maxLines, dp[i]);
    }
    
    cout << n-maxLines << "\n";
}