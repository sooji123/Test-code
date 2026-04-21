#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    int num;
    
    ss >> num;
    int maxNum = num;
    int minNum = num;
    
    while(ss >> num){
        if(num > maxNum){
            maxNum = num;
        }
        if(num < minNum){
            minNum = num;
        }
    }
    
    string answer = to_string(minNum) + " " + to_string(maxNum);
    return answer;
}