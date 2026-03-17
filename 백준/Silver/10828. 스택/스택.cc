#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n;
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        string cmd;
        cin >> cmd;
        
        if(cmd=="push"){
            int x;
            cin >> x;
            s.push(x);
        }else if(cmd=="pop"){
            if(s.empty()){
                cout << -1 << "\n";
            }else{
                cout << s.top() << "\n";
                s.pop();
            }
        }else if(cmd=="size"){
            cout << s.size() << "\n";
        }else if(cmd=="empty"){
            if(s.empty()){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(cmd=="top"){
            if(s.empty()){
                cout << -1 << "\n";
            }else{
                cout << s.top() << "\n";
            }
        }
    }
}