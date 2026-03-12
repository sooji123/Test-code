#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int max_line[3], min_line[3];
    int next_max[3], next_min[3];
    
    for(int i=0;i<3;i++){
        int a;
        cin >> a;
        max_line[i]=a;
        min_line[i]=a;
    }
    
    for(int i=1;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        next_max[0] = a + max(max_line[0], max_line[1]);
        next_max[1] = b + max({max_line[0], max_line[1], max_line[2]});
        next_max[2] = c + max(max_line[1], max_line[2]);
        
        next_min[0] = a + min(min_line[0], min_line[1]);
        next_min[1] = b + min({min_line[0], min_line[1], min_line[2]});
        next_min[2] = c + min(min_line[1], min_line[2]);
        
        for(int j=0;j<3;j++){
            max_line[j] = next_max[j];
            min_line[j] = next_min[j];
        }
    }
    
    cout << *max_element(max_line,max_line+3) << " " << *min_element(min_line,min_line+3) << "\n";
}