#include <bits/stdc++.h>
using namespace std;

int precedence(char op){
    if(op == '+'){
        return 1;
    }
    else if(op == '-'){
        return 1;
    }
    else if(op == '*'){
        return 2;
    }
    else{
        return 2;
    }
}

void processing(stack<string>&postfix, stack<string>&prefix, stack<char>&ops){
    char op = ops.top();
    ops.pop();
    
    string postv2 = postfix.top();
    postfix.pop();
    string postv1 = postfix.top();
    postfix.pop();
    string postAns = postv1 + postv2 + op;
    postfix.push(postAns);
    
    string prev2 = prefix.top();
    prefix.pop();
    string prev1 = prefix.top();
    prefix.pop();
    string preAns = op + prev1 + prev2;
    prefix.push(preAns);
}

int main() {
    string s;
    getline(cin, s);
    
    stack<string>postfix;
    stack<string>prefix;
    stack<char>ops;
    
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == '('){
            ops.push(ch);
        }
        else if(isdigit(ch) || isalpha(ch)){
            // to convert single digit char into string /
            string x = string(1, ch);
            postfix.push(x);
            prefix.push(x);
        }
        else if(ch == ')'){
            while(!ops.empty() && ops.top() != '('){
                processing(postfix, prefix, ops);
            }
            ops.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(!ops.empty() && ops.top() != '(' && precedence(ch) <= precedence(ops.top())){
                processing(postfix, prefix, ops);
            }
            ops.push(ch);
        }
    }
    
    while(!ops.empty()){
        processing(postfix, prefix, ops);
    }
    
    cout << postfix.top() << endl;
    cout << prefix.top() << endl;
}