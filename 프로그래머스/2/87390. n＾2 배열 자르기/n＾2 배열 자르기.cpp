#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; ++i) {
        long long r = i / n;
        long long c = i % n;
        
        answer.push_back(max(r, c) + 1);
    }
    
    return answer;
}