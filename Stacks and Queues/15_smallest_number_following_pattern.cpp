#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    int num = 1;
    stack<int>st;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'd'){
            st.push(num);
            num++;
        }
        else{
            st.push(num);
            num++;
            
            while(!st.empty()){
                int top = st.top();
                st.pop();
                cout << top;
            }
        }
    }
    
    st.push(num);
    while(!st.empty()){
        int top = st.top();
        st.pop();
        cout << top;
    }
    
    return 0;
}