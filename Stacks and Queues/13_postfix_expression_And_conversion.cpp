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
    getline(cin, exp);
    
    stack<int>val;
    stack<string>infix;
    stack<string>prefix;
    
    for(int i = 0; i < exp.size(); i++){
        char ch = exp[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int v2 = val.top();
            val.pop();
            int v1 = val.top();
            val.pop();
            int v = operation(v1, v2, ch);
            val.push(v);
            
            string in2 = infix.top();
            infix.pop();
            string in1 = infix.top();
            infix.pop();
            string in = '(' + in1 + ch + in2 + ')';
            infix.push(in);
            
            string pre2 = prefix.top();
            prefix.pop();
            string pre1 = prefix.top();
            prefix.pop();
            string pre = ch + pre1 + pre2;
            prefix.push(pre);
        }
        else{
            string x = string(1, ch);
            val.push(ch - '0');
            infix.push(x);
            prefix.push(x);
        }
    }
    
    cout << val.top() << endl;
    cout << infix.top() << endl;
    cout << prefix.top() << endl;
}