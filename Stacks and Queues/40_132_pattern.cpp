class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n);
        mini[0] = nums[0];
        // current index tk ka min 
        for(int i = 1; i < n; i++){
            mini[i] = min(mini[i-1], nums[i]);
        }

        stack<int>st;
        bool found = false;
        for(int j = n-1; j >= 0; j--){
            while(!st.empty() && st.top() <= mini[j]){
                st.pop();
            }
            if(!st.empty() && st.top() < nums[j]){
                found = true;
                break;
            }
            st.push(nums[j]);
        }
        return found;
    }
};