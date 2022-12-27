class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        st.push(-1);
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++){
            int val;
            if(i == n){
                val = 0;
            }
            else{
                val = heights[i];
            }

            while(st.top() != -1 && heights[st.top()] >= val){
                int rm = i;
                int h = heights[st.top()];
                st.pop();
                int lm = st.top();
                maxArea = max(maxArea, h*(rm - lm - 1));
            }
            st.push(i);
        }
        return maxArea;
    }
};