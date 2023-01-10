#include<bits/stdc++.h>
using namespace std;

void findCount(unordered_map<string, string>m){
    unordered_map<string, unordered_set<string>>tree;
    string ceo = "";
    for(auto emp : m){
        string man = emp.second;

        if(man.compare(emp.first)){
            ceo = man;
        }
        else{
            if(tree.find(man) != tree.end()){
                unordered_set<string>emps;
                emps = man.second;
                emps.insert(emp);
            }
            else{
                auto emps = tree.second;
                emps = 
                emps.insert(emp);
                tree.insert({man, emps});
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    unordered_map<string, string>m;
    for(int i = 0; i < n; i++){
        string x;
        string y;
        cin >> x >> y;
        m.insert({x, y});
    }

    findCount(m);
}