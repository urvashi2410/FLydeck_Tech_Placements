class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int sign = 1;
        int n = s.size();
        stack<int>st;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(isdigit(ch)){
                int val = 0;
                while(i < n && isdigit(s[i])){
                    val = val*10 + (s[i] - '0');
                    i++;
                }
                i--;
                val = val * sign;
                sign = 1;
                sum += val;
            }
            else if(ch == '('){
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = +1;
            }
            else if(ch == ')'){
                sum *= st.top();
                st.pop();
                sum += st.top();
                st.pop();
            }
            else if(ch == '-'){
                sign *= -1;
            }
        }
        return sum;
    }
};