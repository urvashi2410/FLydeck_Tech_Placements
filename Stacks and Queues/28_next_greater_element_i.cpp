class Solution {
public:
    vector<int>NGR(vector<int>nums){
        int n = nums.size();
        vector<int>ans(n);

        stack<int>s;
        s.push(nums[n-1]);
        ans[n-1] = -1;

        for(int i = n-2; i >= 0; i--){
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

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums2.size();
        vector<int>ngr(n1);
        ngr = NGR(nums2);

        int n2 = nums1.size();
        unordered_map<int, int>m; 
        vector<int>ans(n2);

        for(int i = 0; i < n1; i++){
            m[nums2[i]] = ngr[i];
        }

        for(int i = 0; i < n2; i++){
            ans[i] = m[nums1[i]];
        }

        return ans;
    }
};