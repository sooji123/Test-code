#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int MAX_N = 51;
int A[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

struct Cloud{
    int r, c;
};

vector<Cloud> clouds;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }
    
    clouds.push_back({n-1, 0});
    clouds.push_back({n-1, 1});
    clouds.push_back({n-2, 0});
    clouds.push_back({n-2, 1});
    
    while(m--){
        int d, s;
        cin >> d >> s;
        
        for(int i=0; i<MAX_N; i++){
            for(int j=0; j<MAX_N; j++){
                visited[i][j] = false;
            }
        }
        
        for (auto& cloud : clouds) {
            cloud.r = (cloud.r + (dr[d] * s) % n + n) % n;
            cloud.c = (cloud.c + (dc[d] * s) % n + n) % n;
            
            A[cloud.r][cloud.c]++;
            visited[cloud.r][cloud.c] = true;
        }
        
        for(auto& cloud : clouds){
            int count=0;
            for (int i = 2; i <= 8; i += 2) {
                int nr = cloud.r + dr[i];
                int nc = cloud.c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && A[nr][nc] > 0) {
                    count++;
                }
            }
            
            A[cloud.r][cloud.c] += count;
        }
        
        vector<Cloud> nextClouds;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] >= 2 && !visited[i][j]) {
                    A[i][j] -= 2;
                    nextClouds.push_back({i, j});
                }
            }
        }
        clouds = nextClouds;
    }
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) result += A[i][j];
    }
    cout << result << "\n";

    return 0;
}