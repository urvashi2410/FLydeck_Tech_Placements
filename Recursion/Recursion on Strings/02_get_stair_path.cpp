#include <bits/stdc++.h>
using namespace std;

vector<string> get_stair_paths(int n){
    if(n == 0){
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    if(n < 0){
        vector<string>base;
        return base;
    }
    vector<string>one_stair_paths = get_stair_paths(n - 1);
    vector<string>two_stair_paths = get_stair_paths(n - 2);
    vector<string>three_stair_paths = get_stair_paths(n - 3);
    
    vector<string>all_paths;
    for(auto i : one_stair_paths){
        all_paths.push_back("1" + i);
    }
    for(auto i : two_stair_paths){
        all_paths.push_back("2" + i);
    }
    for(auto i : three_stair_paths){
        all_paths.push_back("3" + i);
    }
    return all_paths;
}
int main(){
    int n;
    cin >> n;
    vector<string>v = get_stair_paths(n);
    for(auto i : v){
        cout << i << endl;
    }
    return 0;
}