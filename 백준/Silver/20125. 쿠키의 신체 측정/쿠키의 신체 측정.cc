#include <iostream>
#include <vector>
#include <string>

using namespace std;

char map[1005][1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    
    pair<int, int> head;
    bool found = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j]=='*'){
                head = {i, j};
                found=true;
                break;
            }
        }
        if(found){
            break;
        }
    }
    
    pair<int, int> heart = {head.first+1, head.second};
    
    int left_arm = 0;
    for(int j = heart.second - 1; j >= 0; j--){
        if(map[heart.first][j]=='*'){
            left_arm++;
        }
        else break;
    }
    
    int right_arm = 0;
    for(int j = heart.second + 1; j < n; j++){
        if(map[heart.first][j]=='*'){
            right_arm++;
        }
        else break;
    }
    
    int waist = 0;
    int waist_end_row = heart.first;
    for(int i=heart.first+1; i<n; i++){
        if(map[i][head.second]=='*'){
            waist++;
            waist_end_row = i;
        }
        else break;
    }
    
    int left_leg = 0;
    for(int i=waist_end_row+1; i<n; i++){
        if(map[i][head.second-1]=='*'){
            left_leg++;
        }
        else break;
    }
    
    int right_leg = 0;
    for(int i=waist_end_row+1; i<n; i++){
        if(map[i][head.second+1]=='*'){
            right_leg++;
        }
        else break;
    }
    
    cout << heart.first+1 << " " << heart.second+1 << "\n";
    cout << left_arm << " " << right_arm << " " << waist << " " << left_leg << " " << right_leg << "\n";
}