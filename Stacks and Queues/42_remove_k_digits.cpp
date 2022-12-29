class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();
        for(int i = 0; i < n; i++){
            char ch = num[i];
            while(!st.empty() && k > 0 && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        vector<char>ans(st.size());
        int i = ans.size() - 1;
        while(i >= 0){
            ans[i--] = st.top();
            st.pop();
        }

        int d = 0;
        while(d < ans.size() && ans[d] == '0'){
            d++;
        }

        string res = "";
        while(d < ans.size()){
            res.push_back(ans[d++]);
        }
        
        if(res.size() == 0){
            res.push_back('0');
        }

        return res;
    }
};