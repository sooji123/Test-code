#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Tower {
    int index;
    int height;
};

int n;
stack<Tower> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        Tower currentTower;
        cin >> currentTower.height;
        currentTower.index = i+1;
        
        while(!s.empty() && s.top().height<currentTower.height){
            s.pop();
        }
        
        if(s.empty()){
            cout << "0" << " ";
        }else{
            cout << s.top().index << " ";
        }
        
        s.push(currentTower);
    }
}