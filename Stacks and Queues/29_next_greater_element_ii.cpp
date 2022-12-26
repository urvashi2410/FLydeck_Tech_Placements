class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;
        vector<int>ans(n);

        if(n <= 1){
            vector<int>base(n);
            base[0] = -1;
            return base;
        }
        // to handle the circular array 
        for(int i = n - 2; i >= 0; i--){
            while(!s.empty() && s.top() <= nums[i]){
                s.pop();

                if(s.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = s.top();
                }
            }
            s.push(nums[i]);
        }

        for(int i = n - 1; i >= 0; i--){
            if(!s.empty() && s.top() <= nums[i]){
                while(!s.empty() && s.top() <= nums[i]){
                    s.pop();

                    if(s.empty()){
                        ans[i] = -1;
                    }
                    else{
                        ans[i] = s.top();
                    }
                }
            }
            else{
                ans[i] = s.top();
            }
            s.push(nums[i]);
        }

        return ans;
    }
};
