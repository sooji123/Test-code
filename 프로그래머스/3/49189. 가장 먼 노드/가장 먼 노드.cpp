#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> adj(n+1);
    for(auto& e : edge){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    
    int max_dist = 0;
    for (int i = 1; i <= n; ++i) {
        max_dist = max(max_dist, dist[i]);
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == max_dist) answer++;
    }

    return answer;
}