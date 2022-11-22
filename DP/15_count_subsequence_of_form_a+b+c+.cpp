#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    
    int a = 0;
    int ab = 0;
    int abc = 0;
    
    for(int i = 0; i < str.size(); i++){
        char ch = str.at(i);
        
        if(ch == 'a'){
            a = 2 * a + 1;
        }
        
        else if(ch == 'b'){
            ab = ab * 2 + a;
        }
        
        else if(ch == 'c'){
            abc = abc * 2 + ab;
        }
    }
    
    cout << abc << endl;
}