class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>leftMax(n+1);
        vector<int>rightMin(n+1);

        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            maxi = max(arr[i], maxi);
            leftMax[i] = maxi;
        }
        leftMax[n] = maxi;

        rightMin[n] = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            mini = min(arr[i], mini);
            rightMin[i] = mini;
        }
        
        int j;
        int count = 0;
        for(int i = 0; i < n; i++){
            j = i + 1;
            if(leftMax[i] <= rightMin[j]){
                count++;
            }
        }
        return count;
    }
};