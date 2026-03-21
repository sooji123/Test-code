#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input , bomb;
    cin >> input >> bomb;
    
    string result = "";
    
    for(char c : input){
        result.push_back(c);
        
        if(result.size() >= bomb.size()){
            bool match = true;
            for(int i=0; i<bomb.size(); i++){
                if(result[result.size() - bomb.size() + i] != bomb[i]){
                    match = false;
                    break;
                }
            }
            if(match){
                for (int i = 0; i < bomb.size(); i++) result.pop_back();
            }
        }
        
    }
    
    if(result.empty()){
        result = "FRULA";
    }
    
    cout << result << "\n";
}