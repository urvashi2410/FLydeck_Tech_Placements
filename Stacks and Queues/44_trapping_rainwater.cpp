class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] <= height[i]){
                int rm = i;
                int curr = height[st.top()];
                st.pop();
                if(st.empty()){
                    break;
                }
                int lm = st.top();
                int width = rm - lm - 1;
                ans += (min(height[rm], height[lm]) - curr) * width;
            }
            st.push(i);
        }
        return ans;
    }
};