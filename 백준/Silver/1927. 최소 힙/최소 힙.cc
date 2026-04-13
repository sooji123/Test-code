#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> q;
    
    while(n--){
        int x;
        cin >> x;
        
        if(x==0){
            if(q.empty()){
                cout << 0 << "\n";
            }else{
                cout << q.top() << "\n";
                q.pop();
            }
        }else{
            q.push(x);
        }
    }
    
    return 0;
}