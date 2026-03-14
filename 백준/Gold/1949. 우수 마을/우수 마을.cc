#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;

int N;
int people[MAX];
vector<int> graph[MAX];
int dp[MAX][2];
bool visited[MAX];

void dfs(int u) {
    visited[u] = true;
    dp[u][1] = people[u];

    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);

            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> people[i];

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}