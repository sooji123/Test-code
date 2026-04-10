#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Team{
    int id;
    vector<int> scores;
    int fifthRunnerScore;
    int memberCount;
    int totalScore;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<int> ranks(n);
        map<int, int> teamMemberCount;
        
        for(int i=0; i<n; i++){
            cin >> ranks[i];
            teamMemberCount[ranks[i]]++;
        }
        
        map<int, Team> teams;
        int currentScore=1;
        
        for(int i=0; i<n; i++){
            int teamId = ranks[i];
            if (teamMemberCount[teamId] == 6) {
                if (teams[teamId].memberCount < 4) {
                    teams[teamId].totalScore += currentScore;
                } else if (teams[teamId].memberCount == 4) {
                    teams[teamId].fifthRunnerScore = currentScore;
                }
                teams[teamId].memberCount++;
                teams[teamId].id = teamId;
                currentScore++;
            }
        }
        
        int winnerId = -1;
        int minScore = 1e9;
        int minFifthScore = 1e9;

        for (auto const& [id, team] : teams) {
            if (team.totalScore < minScore) {
                minScore = team.totalScore;
                minFifthScore = team.fifthRunnerScore;
                winnerId = id;
            } else if (team.totalScore == minScore) {
                if (team.fifthRunnerScore < minFifthScore) {
                    minFifthScore = team.fifthRunnerScore;
                    winnerId = id;
                }
            }
        }
        
        cout << winnerId << "\n";
    }
    
    return 0;
}