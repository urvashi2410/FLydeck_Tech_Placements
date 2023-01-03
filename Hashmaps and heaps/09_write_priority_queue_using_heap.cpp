// push = O(logn)
// remove = O(logn)
// top = O(1)

#include<bits/stdc++.h>
using namespace std;

vector<int> data;

int _size() {
    return data.size();
}

void upheapify(int i){
    while(i > 0){
        int parentIdx = (i - 1)/2;
        if(data[i] < data[parentIdx]){
            swap(data[i], data[parentIdx]);
        }
        else{
            break;
        }
        i = parentIdx;
    }
}

void add(int val) {
    data.push_back(val);
    upheapify(data.size() - 1);
}

void downheapify(int i){
    while(true){
        int leftIdx = i*2 + 1;
        int rightIdx = i*2 + 2;
        
        int mini = i;
        if(leftIdx < data.size() && data[leftIdx] < data[mini]){
            mini = leftIdx;
        }
        if(rightIdx < data.size() && data[rightIdx] < data[mini]){
            mini = rightIdx;
        }
        if(i == mini){
            break;
        }
        swap(data[i], data[mini]);
        i = mini;
    }
}

int _remove() {
    if(_size() == 0){
        cout << "Underflow" << endl;
        return -1;
    }
    swap(data[0], data[data.size() - 1]);
    int val = data[data.size() - 1];
    data.pop_back();
    downheapify(0);
    return val;
}

int peek() {
    if(_size() == 0){
        cout << "Underflow" << endl;
        return -1;
    }
    
    return data[0];
}

int main() {
    while (1) {
        string str;
        getline(cin, str);
        if (str[0] == 'a') {
            string num = str.substr(4, str.length());
            int val = stoi(num);
            add(val);
        } 
        else if (str[0] == 'r') {
            int val = _remove();
            if (val != -1) {
                cout << val << endl;
            }
        } 
        else if (str[0] == 'p') {
            int val = peek();
            if (val != -1) {
                cout << val << endl;
            }
        } 
        else break;
    }
}
