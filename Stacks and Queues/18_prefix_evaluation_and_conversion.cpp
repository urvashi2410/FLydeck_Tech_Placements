#include <bits/stdc++.h>
using namespace std;

int operation(int v1, int v2, char ch){
    if(ch == '+'){
        return v1 + v2;
    }
    else if(ch == '-'){
        return v1 - v2;
    }
    else if(ch == '*'){
        return v1 * v2;
    }
    else{
        return v1 / v2;
    }
}

int main() {
    string exp;
    cin >> exp;
    
    stack<int>val;
    stack<string>postfix;
    stack<string>infix;
    
    for(int i = exp.size() - 1; i >= 0; i--){
        char ch = exp[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int v1 = val.top();
            val.pop();
            int v2 = val.top();
            val.pop();
            int value = operation(v1, v2, ch);
            val.push(value);
            
            string in1 = infix.top();
            infix.pop();
            string in2 = infix.top();
            infix.pop();
            string inval = '(' + in1 + ch + in2 + ')';
            infix.push(inval);
            
            string pos1 = postfix.top();
            postfix.pop();
            string pos2 = postfix.top();
            postfix.pop();
            string postval = pos1 + pos2 + ch;
            postfix.push(postval);
        }
        else{
            val.push(ch - '0');
            string x = string(1, ch);
            infix.push(x);
            postfix.push(x);
        }
    }
    cout << val.top() << endl;
    cout << infix.top() << endl;
    cout << postfix.top() << endl;
    return 0;
}