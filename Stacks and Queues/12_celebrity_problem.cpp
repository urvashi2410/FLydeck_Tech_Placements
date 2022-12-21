//Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        // code here 
        stack<int>st;
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() >= 2){
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            
            if(arr[i][j] == 1){
                // means i knows j => i is not a celebrity 
                st.push(j);
            }
            else{
                // means i does not know j => j is not a celebrity 
                st.push(i);
            }
        }
        
        int pos = st.top();
        st.pop();
        for(int i = 0; i < n; i++){
            if(i != pos){
                if(arr[i][pos] == 0 || arr[pos][i] == 1){
                    return -1;
                }
            }
        }
        
        return pos;
    }