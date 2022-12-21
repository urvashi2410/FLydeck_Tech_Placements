class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 1;
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(element == nums[i]){
                count++;
            }
            else{
                count--;
            }

            if(count == 0){
                element = nums[i];
                count = 1;
            }
        }

        count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == element){
                count++;
            }
        }

        if(count >= n/2){
            return element;
        }
        return -1;
    }
};