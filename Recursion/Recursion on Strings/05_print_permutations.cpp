#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    if(str.size() == 0){
        cout << asf << endl;
        return;
    }
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        string remPermutation = str.substr(0, i) + str.substr(i + 1);
        printPermutations(remPermutation, asf + ch);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
}