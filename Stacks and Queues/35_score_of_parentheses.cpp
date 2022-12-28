class Solution {
public:
    int scoreOfParentheses(string s) {
        // '(' = -1
        // ')' = 0
        stack<int>st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '('){
                st.push(-1);
            }
            else{
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int val = 0;
                    while(st.top() != -1){
                        val += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(val*2);
                }
            }
        }
        int val = 0;
        while(!st.empty()){
            val += st.top();
            st.pop();
        }
        return val;
    }
};