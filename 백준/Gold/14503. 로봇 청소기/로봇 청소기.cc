#include <iostream>
#include <vector>

using namespace std;

int n, m;
int r, c ,d;
int map[50][50];
int result = 0;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    cin >> r >> c >> d;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    
    while(true){
        if(map[r][c]==0){
            map[r][c] = -1;
            result++;
        }
        
        bool uncleaned = false;
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(map[nr][nc]==0){
                    uncleaned = true;
                    break;
                }
            }
        }
        
        if(uncleaned==false){
            int back = (d+2) % 4;
            int br = r + dr[back];
            int bc = c + dc[back];
            
            if(br>=0 && br<n && bc>=0 && bc<m && map[br][bc]!=1){
                r = br;
                c = bc;
            }else{
                break;
            }
        }else{
            d = (d+3)%4;
            
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && map[nr][nc]==0){
                r = nr;
                c = nc;
            }
        }
    }
    
    cout << result << "\n";
}