#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> queue(works.begin(), works.end());
    
    for(int i=0;i<n;i++){
        if(queue.top()>0){
            int maxNum = queue.top();
            queue.pop();
            queue.push(maxNum-1);
        }else{
            break;
        }
    }
    
    while(queue.empty()==false){
        long long remain = queue.top();
        queue.pop();
        answer += remain*remain;
    }
    return answer;
}