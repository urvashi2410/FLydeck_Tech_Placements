class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch : s){
            if(ch == 'c'){
                if(st.size() < 2){
                    return false;
                }
                if(st.top() != 'b'){
                    return false;
                }
                st.pop();
                if(st.top() != 'a'){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        return st.size() == 0;
    }
};