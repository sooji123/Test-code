#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    queue<int> s;
    
    for(int i=1; i<=n; i++){
        s.push(i);
    }
    
    while(s.size() > 1){
        s.pop();
        
        int second = s.front();
        s.pop();
        s.push(second);
    }
    
    cout << s.front() << "\n";
}