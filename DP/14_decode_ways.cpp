#include<iostream>
#include<vector>
#include<string>
using namespace std;

int decodeWays(string str){
    vector<int>dp(str.size());
    int ans;
    dp[0] = 1;

    for (int i = 1; i < str.length(); i++) {
        if (str[i - 1] == '0' && str[i] == '0') {
            dp[i] = i >= 2 ? dp[i - 2] : 1;
        } 
        else if (str[i - 1] == '0' && str[i] != '0') {
            dp[i] = dp[i - 1];
        } 
        else if (str[i - 1] != '0' && str[i] == '0') {
            dp[i] = dp[i - 2];
        } 
        else {
            if(stoi(str.substr(i - 1, i + 1)) <= 26){
                dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            }
            else{
                dp[i] = dp[i - 1];
            }
        }
    }
    return dp[str.length() - 1];
}
int main(){
    string str;
    cin >> str;
    
    cout << decodeWays(str);
}