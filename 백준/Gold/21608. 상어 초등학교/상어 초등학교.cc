#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int map[21][21];
int likes[401][4];
vector<int> order;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct Seat {
    int r;
    int c;
    int likeCnt;
    int emptyCnt;
};

bool compare(Seat a, Seat b) {
    if (a.likeCnt != b.likeCnt){
        return a.likeCnt > b.likeCnt;
    }
    if (a.emptyCnt != b.emptyCnt){
        return a.emptyCnt > b.emptyCnt;
    }
    if (a.r != b.r){
        return a.r < b.r;
    }
    return a.c < b.c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n * n; i++) {
        int student;
        cin >> student;
        order.push_back(student);
        
        for (int j = 0; j < 4; j++){
            cin >> likes[student][j];
        }
    }
    
    for (int idx = 0; idx < order.size(); idx++) {
        int curr = order[idx];
        vector<Seat> candidates;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] != 0){
                    continue;
                }

                int lCnt = 0, eCnt = 0;
                for (int d = 0; d < 4; d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];

                    if (nr < 1 || nr > n || nc < 1 || nc > n){
                        continue;
                    }

                    if (map[nr][nc] == 0){
                        eCnt++;
                    } else {
                        for (int k = 0; k < 4; k++) {
                            if (map[nr][nc] == likes[curr][k]) {
                                lCnt++;
                                break;
                            }
                        }
                    }
                }
                candidates.push_back({i, j, lCnt, eCnt});
            }
        }
        sort(candidates.begin(), candidates.end(), compare);
        map[candidates[0].r][candidates[0].c] = curr;
    }
    
    long long totalSatisfaction = 0;
    int score[] = {0, 1, 10, 100, 1000};
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int student = map[i][j];
            int count = 0;
            for (int d = 0; d < 4; d++) {
                int nr = i + dr[d];
                int nc = j + dc[d];
                
                if (nr < 1 || nr > n || nc < 1 || nc > n){
                    continue;
                }

                for (int k = 0; k < 4; k++) {
                    if (map[nr][nc] == likes[student][k]) {
                        count++;
                        break;
                    }
                }
            }
            totalSatisfaction += score[count];
        }
    }

    cout << totalSatisfaction << "\n";

    return 0;
}