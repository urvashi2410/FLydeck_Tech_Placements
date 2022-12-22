#include<bits/stdc++.h>
using namespace std;

bool compare(const vector<int>v1, const vector<int>v2){
    // 0 index is of start time 
    return v1[0] < v2[0];
}

void mergeOverlappingIntervals(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end());
    stack<vector<int>>st;
    
    for(int i = 0; i < arr.size(); i++){
        vector<int>pair = arr[i];
        int start = pair[0];
        int end = pair[1];
        
        if(i == 0){
            st.push(pair);
        }
        else{
            vector<int>top = st.top();
            st.pop();
            // current meeting ka start time agar bda h stack k top wali k end time se 
            if(start > top[1]){
                st.push(top);
                st.push(pair);
            }
            else{
                vector<int>merge;
                merge.push_back(top[0]);
                top[1] = max(top[1], pair[1]);
                merge.push_back(top[1]);
                
                st.push(merge);
            }
        }
    }
    
    stack<vector<int>>resultStack;
    while(!st.empty()){
        resultStack.push(st.top());
        st.pop();
    }
    
    while(!resultStack.empty()){
        vector<int> ans = resultStack.top();
        resultStack.pop();
        
        cout << ans[0] << " " << ans[1] << endl;
    }
}


int main() {
    int n;
    cin >> n ;

    vector<vector<int>> arr( n, vector<int>(2) );
    
    for (int i = 0; i < n ; i++ ) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    mergeOverlappingIntervals(arr);

}