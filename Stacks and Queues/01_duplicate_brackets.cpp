// not submitted on pepcoding 

#include<bits/stdc++.h>
using namespace std;

void isDuplicate(string s){
    stack<char>st;
    for(int i = 0 ; i < s.length(); i++){
        char ch = s[i];
        if(ch == ')'){
            if(st.top() == '('){
                cout << "true" << endl;
                return;
            }
            else{
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        }
        else{
            st.push(ch);
        }
    }
    cout << "false" << endl;
}

int main(){
    string s;
    cin >> s;
    isDuplicate(s);
}