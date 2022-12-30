// not complete 

#include<bits/stdc++.h>
using namespace std;

class Pair{

}

int calculate(string s) {
        stack<int>st;
        
        int n = s.size();
        char sign = '+';

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(isdigit(ch)){
                int val = 0;
                while(i < n && isdigit(s[i])){
                    val = val*10 + (s[i] - '0');
                    i++;
                }
                i--;
                cal(st, val, sign);
            }
            else if(ch == '('){
                stP.push()
            }
            else if(ch != ' '){
                sign = ch;
            }
        }

        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }

int main(){
    string s;
    cin >> s;
    cout << calculate(s);
    return 0;
}