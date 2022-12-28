class Solution {
public:
    void convert(string s, int &id, string &operation, int &time){
        int j = 0;
        id = time = 0;
        while(s[j] != ':'){
            id = id*10 + s[j] - '0';
            j++;
        }
        j++;
        while(s[j] != ':'){
            operation.push_back(s[j]);
            j++;
        }
        j++;
        while(j < s.size()){
            time = time*10 + s[j] - '0';
            j++;
        }
        if(operation == "end"){
            time++;
        }
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> duration(n, 0);
        stack<int>s;
        int prev_op_time;
        for(int i = 0; i < logs.size(); i++){
            int id, time;
            string operation;
            convert(logs[i], id, operation, time);
            if(!s.empty()){
                int fn_id = s.top();
                duration[fn_id] += (time - prev_op_time);
            }
            prev_op_time = time;
            
            if(operation == "start"){
                s.push(id);
            }
            else{
                s.pop();
            }
        }
        return duration;
    }
};