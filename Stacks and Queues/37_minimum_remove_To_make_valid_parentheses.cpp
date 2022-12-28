class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        vector<char>v(s.size());
        for(int i = 0; i < s.size(); i++){
            v[i] = s[i];
        }

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else if(ch == ')'){
                if(st.empty()){
                    v[i] = '.';
                }
                else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            v[st.top()] = '.';
            st.pop();
        }

        string ans = "";
        for(char c : v){
            if(c != '.'){
                ans.push_back(c);
            }
        }
        return ans;
    }
};