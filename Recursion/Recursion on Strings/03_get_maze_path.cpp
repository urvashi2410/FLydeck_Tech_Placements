#include<bits/stdc++.h>
using namespace std;

vector<string> get_maze_path(int n, int m, int i, int j){
    if(i == n - 1 && j == m - 1){
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    
    vector<string>ans;
    if(i < n){
        vector<string>ans1 = get_maze_path(n, m, i+1, j);
        for(auto smallAns : ans1){
            string path = "v" + smallAns;
            ans.push_back(path);
        }
    }
    if(j<m){
        vector<string>ans2 = get_maze_path(n, m, i, j+1);
        for(auto smallAns : ans2){
            string path = "h" + smallAns;
            ans.push_back(path);
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<string> v = get_maze_path(n, m, 0, 0);
    for(auto i : v){
        cout << i << endl;
    }
    cout << v.size();
}