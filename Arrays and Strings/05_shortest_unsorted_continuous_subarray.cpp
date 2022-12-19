class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int element = nums[0];
        int end = INT_MAX;
        for(int i = 1; i < n; i++){
            if(element > nums[i]){
                end = i;
            }
            else{
                element = nums[i];
            }
        }

        int element1 = nums[n-1];
        int start = INT_MIN;
        for(int i = n - 2; i >= 0; i--){
            if(element1 < nums[i]){
                start = i;
            }
            else{
                element1 = nums[i];
            }
        }
        
        if(start == INT_MIN && end == INT_MAX){
            return 0;
        }
        else{
            return end - start + 1;
        }
    }
};
