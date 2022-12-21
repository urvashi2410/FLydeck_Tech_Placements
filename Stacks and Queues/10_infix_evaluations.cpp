#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int precedence(char optor){
    if(optor == '+'){
        return 1;
    }
    else if(optor == '-'){
        return 1;
    }
    else if(optor == '*'){
        return 2;
    }
    else{
        return 2;
    }
}

int operation(int v1, int v2, char optor){
    if(optor == '+'){
        return v1 + v2;
    }
    else if(optor == '-'){
        return v1 - v2;
    }
    else if(optor == '*'){
        return v1 * v2;
    }
    else{
        return v1 / v2;
    }
}

int main() {
    string str;
    getline(cin, str);
    
    stack<int>opnds;
    stack<char>optors;
    
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(ch == '('){
            optors.push(ch);
        }
        else if(isdigit(ch)){
            opnds.push(ch-'0');
        }
        else if(ch == ')'){
            while(optors.top() != '('){
                char op = optors.top();
                optors.pop();
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                
                int ans = operation(v1, v2, op);
                opnds.push(ans);
            }
            optors.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(!optors.empty() && optors.top() != '(' && (precedence(optors.top()) >= precedence(ch))){
                char op = optors.top();
                optors.pop();
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                
                int ans = operation(v1, v2, op);
                opnds.push(ans);
            }
            optors.push(ch);
        }
    }
    
    while(!optors.empty()){
        char op = optors.top();
        optors.pop();
        int v2 = opnds.top();
        opnds.pop();
        int v1 = opnds.top();
        opnds.pop();
                
        int ans = operation(v1, v2, op);
        opnds.push(ans);
    }
    
    cout << opnds.top() << endl;
    return 0;
}