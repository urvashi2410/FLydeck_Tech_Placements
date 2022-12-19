class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int h;
        int area;
        int ans = INT_MIN;
        while(i < j){
            if(height[i] > height[j]){
                h = height[j];
            }
            else{
                h = height[i];
            }

            area = h * (j - i);
            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }

            ans = max(ans, area);
        }
        return ans;
    }
};