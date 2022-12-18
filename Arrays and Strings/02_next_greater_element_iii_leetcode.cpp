class Solution {
public:
    int nextGreaterElement(int num) {
        string arr = to_string(num);
        int n = arr.size();

        if(n == 1){
            return -1;
        }
        set<char>s;
        for(int i = 0; i < n; i++){
            s.insert(arr[i]);
        }

        if(s.size() == 1){
            return -1;
        }

        int i;
        for(i = n-1; i >= 1; i--){
            if(arr[i-1] < arr[i]){
                break;
            }
        }
        
        if(i != 0){
            for(int j = n-1; j >= i; j--){
                if(arr[i-1] < arr[j]){
                    swap(arr[i-1], arr[j]);
                    break;
                }
            }
        }
        reverse(arr.begin() + i, arr.end());
        long long ans = stol(arr);
        if(ans > INT_MAX || ans < INT_MIN){
            return -1;
        }

        if(ans < num){
            return -1;
        }
        return ans;
    }
};