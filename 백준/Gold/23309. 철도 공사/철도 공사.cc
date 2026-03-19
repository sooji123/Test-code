#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n,m;
int prev_node[1000001];
int next_node[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    vector<int> station(n);
    for(int i=0; i<n; i++){
        cin >> station[i];
    }
    
    for (int i = 0; i < n; i++) {
        int curr = station[i];
        int prev = station[(i - 1 + n) % n];
        int next = station[(i + 1) % n];
        prev_node[curr] = prev;
        next_node[curr] = next;
    }
    
    while(m--){
        string cmd;
        cin >> cmd;
        
        int i, j;
        
        if(cmd=="BN"){
            cin >> i >> j;
            
            int target = next_node[i];
            
            next_node[i] = j;
            prev_node[j] = i;
            next_node[j] = target;
            prev_node[target] = j;
            
            cout << target << "\n";
        }else if(cmd=="BP"){
            cin >> i >> j;
            
            int target = prev_node[i];
            
            next_node[target] = j;
            prev_node[j] = target;
            next_node[j] = i;
            prev_node[i] = j;
            
            cout << target << "\n";
        }else if(cmd=="CN"){
            cin >> i;
            
            int target = next_node[i];
            int after_target = next_node[target];
            
            next_node[i] = after_target;
            prev_node[after_target] = i;
            
            cout << target << "\n";
        }else if(cmd=="CP"){
            cin >> i;
            
            int target = prev_node[i];
            int before_target = prev_node[target];
            
            next_node[before_target] = i;
            prev_node[i] = before_target;
            
            cout << target << "\n";
        }
    }
}