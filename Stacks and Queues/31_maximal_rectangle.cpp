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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>heights(m);

        for(int i = 0; i < m; i++){
            char ch = matrix[0][i];
            heights[i] = ch - '0';
        }

        int area = largestRectangleArea(heights);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            area = max(area, largestRectangleArea(heights));
        }
        return area;
    }
};