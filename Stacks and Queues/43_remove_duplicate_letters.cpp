class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        vector<int>freq(26);
        vector<bool>exist(26);
        int n = s.size();

        for(int i = 0; i < n; i++){
            char ch = s[i];
            freq[ch - 'a']++;
        }

        for(int i = 0; i < n; i++){
            char ch = s[i];
            freq[ch - 'a']--;
            if(exist[ch - 'a']){
                continue;
            }

            while(!st.empty() && st.top() > ch && freq[st.top() - 'a'] > 0){
                char rem = st.top();
                st.pop();
                exist[rem - 'a'] = false;
            }

            st.push(ch);
            exist[ch - 'a'] = true;
        }

        vector<char>ans(st.size());
        int i = ans.size() - 1;
        while(i >= 0){
            ans[i--] = st.top();
            st.pop();
        }

        string rem = "";
        for(int i = 0; i < ans.size(); i++){
            rem.push_back(ans[i]);
        }
        return rem;
    }
};