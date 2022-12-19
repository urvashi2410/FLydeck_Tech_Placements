class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int k = n - 1;
        vector<int>ans(n);

        while(i <= j){
            int x1 = nums[i] * nums[i];
            int x2 = nums[j] * nums[j];

            if(x1 > x2){
                ans[k] = x1;
                i++;
            }
            else{
                ans[k] = x2;
                j--;
            }
            k--;
        }
        return ans;
    }
};