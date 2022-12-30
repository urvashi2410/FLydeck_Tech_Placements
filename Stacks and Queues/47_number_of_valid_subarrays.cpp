#include<bits/stdc++.h>
using namespace std;

int validSubarrays(vector<int>nums){
    stack<int>st;
    int ans = 0;
    int n = nums.size();

    for(int i = n-1; i >= 0; i--){
        int val = nums[i];
        while(!st.empty() && nums[st.top()] >= val){
            st.pop();
        }

        int si = n;
        if(!st.empty()){
            si = st.top();
        }
        ans += si - i;
        st.push(i);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    cout << validSubarrays(nums);
}