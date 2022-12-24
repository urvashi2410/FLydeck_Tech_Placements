vector<long long> printFirstNegativeInteger(long long int nums[], long long int n, long long int k) {
    long long i = 0;
    long long j = 0;
    queue<long long>q;
    vector<long long>ans;
    
    for(j = 0; j < k; j++){
        if(nums[j] < 0){
            q.push(nums[j]);
        }
    }
    
    while(j <= n){
        if(q.size() == 0){
            ans.push_back(0);
        }
        else{
            ans.push_back(q.front());
        }
        if(nums[i] < 0){
            q.pop();
        }
        if(nums[j] < 0){
            q.push(nums[j]);
        }
        i++;
        j++;
    }
    return ans;
 }