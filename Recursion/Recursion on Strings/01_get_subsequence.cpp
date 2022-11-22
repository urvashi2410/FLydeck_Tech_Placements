#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    if(s.size() == 0){
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    vector<string>ans;
    char first = s[0];
    string rem = s.substr(1);
    vector<string>smallAns = gss(rem);
    for(int i = 0; i < smallAns.size(); i++){
        string sequence = first + smallAns[i];
        ans.push_back("" + smallAns[i]);
        ans.push_back(sequence);
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}