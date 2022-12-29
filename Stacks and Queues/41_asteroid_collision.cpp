class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int val : asteroids){
            if(val > 0){
                st.push(val);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -val){
                    st.pop();
                }
                if(!st.empty() && st.top() == -val){
                    st.pop();
                }
                else if(!st.empty() && st.top() > -val){

                }
                else{
                    st.push(val);
                }
            }
        }

        vector<int>ans(st.size());
        int i = ans.size() - 1;
        while(i >= 0){
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};