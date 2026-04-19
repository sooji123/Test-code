#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[101][101];
bool hasPath[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i=1; i<=n; i++) {
        dist[i][i] = 0;
        hasPath[i][i] = true;
    }
    
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        if (!hasPath[u][v] || w < dist[u][v]) {
            dist[u][v] = w;
            hasPath[u][v] = true;
        }
    }
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (hasPath[i][k] && hasPath[k][j]) {
                    int newDist = dist[i][k] + dist[k][j];
                    
                    if (!hasPath[i][j] || newDist < dist[i][j]) {
                        dist[i][j] = newDist;
                        hasPath[i][j] = true;
                    }
                }
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!hasPath[i][j] || i == j) {
                if (i!=j && !hasPath[i][j]){
                    cout << "0 ";
                }else {
                    cout << "0 "; 
                }
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
}