#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> counts;
    for(const auto& item : clothes){
        counts[item[1]]++;
    }
    
    int answer = 1;
    for(auto const& [type, count] : counts){
        answer *= (count+1);
    }
    return answer-1;
}