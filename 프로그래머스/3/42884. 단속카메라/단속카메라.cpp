#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int last_camera = -30001;
    
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    for(auto& route : routes){
        if(route[0]>last_camera){
            answer++;
            last_camera = route[1];
        }
    }
    
    return answer;
}