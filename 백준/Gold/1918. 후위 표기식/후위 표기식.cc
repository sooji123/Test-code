#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char op) {
    if (op == '(' || op == ')') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    cin >> input;
    
    stack<char> s;
    
    for(char c : input){
        if(c >= 'A' && c <= 'Z'){
            cout << c;
        }else if(c == '('){
            s.push(c);
        }else if(c == ')'){
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }else{
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
        
    }
    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}