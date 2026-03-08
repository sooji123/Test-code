#include <iostream>
#include <vector>

using namespace std;

int n;
char rgb[101][101];
bool visited[101][101];

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

void find(int r,int c){
    visited[r][c]=true;
    
    for(int i=0 ; i<4 ; i++){
        int nr = r+dr[i];
        int nc = c+dc[i];
        
        if(nc>=0 && nc<n && nr>=0 && nr<n){
           if(rgb[nr][nc]==rgb[r][c] && visited[nr][nc]==false){
               find(nr,nc);
           }
        }
    }
}

int main(){
    cin >> n;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> rgb[i][j];
        }
    }
    
    int countNormal=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(visited[i][j]==false){
                find(i,j);
                countNormal ++;
            }
        }
    }
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            visited[i][j]=false;
            if(rgb[i][j]=='R'){
                rgb[i][j]='G';
            }
        }
    }
    
    int countNotNormal=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(visited[i][j]==false){
                find(i,j);
                countNotNormal ++;
            }
        }
    }
    
    cout << countNormal << " " << countNotNormal <<endl;
}