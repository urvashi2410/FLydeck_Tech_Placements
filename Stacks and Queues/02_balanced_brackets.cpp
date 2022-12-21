// not submitted on pepcoding 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    stack<char>st;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if(ch == ')'){
            if(st.size() == 0 || st.top() != '('){
                cout << "false";
                return 0;
            }
            else{
                st.pop();
            }
        }
        else if(ch == '}'){
            if(st.size() == 0 || st.top() != '{'){
                cout << "false";
                return 0;
            }
            else{
                st.pop();
            }
        }
        else if(ch == ']'){
            if(st.size() == 0 || st.top() != '['){
                cout << "false";
                return 0;
            }
            else{
                st.pop();
            }
        }
    }
    
    if(st.size() == 0){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}