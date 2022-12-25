#include<iostream>
#include <string>
#include <stack>

using namespace std;


class MinStack {
  stack<int> data;
  int minVal;


public:
  int size() {
      return data.size();
  }

public:
  void push(int val) {
      if(data.size() == 0){
          data.push(val);
          minVal = val;
      }
      else if(val >= minVal){
          data.push(val);
      }
      else{
          data.push(val + (val - minVal));
          minVal = val;
      }
  }

public:
  int pop() {
      if(data.size() == 0){
          cout << "Stack underflow" << endl;
          return -1;
      }
      else{
          if(data.top() >= minVal){
              int val = data.top();
              data.pop();
              return val;
          }
          else{
              int val = minVal;
              minVal = minVal * 2 - data.top();
              data.pop();
              return val;
          }
      }
  }

public:
  int top() {
      if(data.size() == 0){
          cout << "Stack underflow" << endl;
          return -1;
      }
      else{
          if(data.top() >= minVal){
              return data.top();
          }
          else{
              return minVal;
          }
      }
  }

public:
  int min() {
      if(size() == 0){
          cout << "Stack underflow" << endl;
          return -1;
      }
      else{
          return minVal;
      }
  }

};


int main() {
  MinStack st;

  string str;
  cin >> str;

  while (str != "quit") {

    if (str == "push") {
      int val;
      cin >> val;
      st.push(val);
    }
    else if (str == "pop") {
      int val = st.pop();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "top") {
      int val = st.top();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << st.size() << endl;
    }
    else if (str == "min" ) {
      int val = st.min();
      if (val != -1) {
        cout << val << endl;
      }
    }

    cin >> str;

  }

}