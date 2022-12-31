#include<bits/stdc++.h>
using namespace std;

class MaxStack{
    public:
        stack<int>data;
        stack<int>maxi;

        MaxStack(){
        }

        void push(int x){
            data.push(x);
            int m = x;
            if(maxi.size() > 0){
                m = max(m, maxi.top());
                maxi.push(m);
            }
        }

        int pop(){
            maxi.pop();
            int ans = data.top();
            data.pop();
            return ans;
        }

        int top(){
            return data.top();
        }

        int peekMax(){
            return maxi.top();
        }

        int popMax(){
            int tbr = maxi.top();
            stack<int>buffer;
            while(data.top() != tbr){
                int res = pop();
                buffer.push(res);
            }

            pop();
            while(buffer.size() > 0){
                int res = buffer.top();
                buffer.pop();
                push(res);
            }
            return tbr;
        }
    
};