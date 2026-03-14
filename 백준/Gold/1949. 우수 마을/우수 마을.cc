#include <bits/stdc++.h>
using namespace std;

const long long INF = -1e18;

int N;
long long w[10001];
vector<int> graph[10001];
long long dp[10001][3];
bool visited[10001];

void dfs(int u){
    visited[u] = true;

    dp[u][0] = w[u];
    dp[u][1] = 0;
    dp[u][2] = 0;

    long long extra = INF;
    bool hasChild = false;

    for(int v : graph[u]){
        if(visited[v]) continue;
        hasChild = true;

        dfs(v);

        dp[u][0] += dp[v][1];

        dp[u][1] += max(dp[v][0], dp[v][2]);

        long long best = max(dp[v][0], dp[v][2]);
        dp[u][2] += best;

        extra = max(extra, dp[v][0] - best);
    }

    if(!hasChild){
        dp[u][2] = INF;
    }else{
        dp[u][2] += extra;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for(int i=1;i<=N;i++)
        cin >> w[i];

    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][2]) << '\n';
}