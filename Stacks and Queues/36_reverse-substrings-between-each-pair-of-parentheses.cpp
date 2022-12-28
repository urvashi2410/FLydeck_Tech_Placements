class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == ')'){
                queue<char>q;
                while(st.top() != '('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            }
            else{
                // ch = '(' or abc... 
                st.push(ch);
            }
        }

        vector<char>ans(st.size());
        int i = st.size() - 1;
        while(i >= 0){
            ans[i] = st.top();
            st.pop();
            i--;
        }

        string res = "";
        for(char ch : ans){
            res += ch;
        }
        return res;
    }
};