#include <iostream>
#include<string>
#include<vector>
using namespace std;

int solution(string s)
{
    vector<char> stack;
    
    for(char c : s){
        if(!stack.empty() && stack.back() == c){
            stack.pop_back();
        } else {
            stack.push_back(c);
        }
    }
    return stack.empty() ? 1 : 0;
}