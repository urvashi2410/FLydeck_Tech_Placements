#include <iostream>
#include <exception>
#include <stack>
using namespace std;

class StackToQueueAdapter {
public:
  stack<int> mainS;
  stack<int> helperS;

  int size() {
      return mainS.size();
  }

  void add(int data) {
      mainS.push(data);
  }

  int peek() {
      if(size() == 0){
          cout << "Queue underflow" << endl;
          return -1;
      }
      else{
          while(mainS.size() > 1){
              int val = mainS.top();
              mainS.pop();
              helperS.push(val);
          }
          
          int val = mainS.top();
          mainS.pop();
          helperS.push(val);
          
          while(!helperS.empty()){
              int val = helperS.top();
              helperS.pop();
              mainS.push(val);
          }
          return val;
      }
  }

  int remove() {
      if(size() == 0){
          cout << "Queue underflow" << endl;
          return -1;
      }
      else{
          while(mainS.size() > 1){
              int val = mainS.top();
              mainS.pop();
              helperS.push(val);
          }
          
          int val = mainS.top();
          mainS.pop();
          
          while(!helperS.empty()){
              int val = helperS.top();
              helperS.pop();
              mainS.push(val);
          }
          return val;
      }
  }
};

int main() {
  StackToQueueAdapter q;
  string str;
  cin >> str;

  while (str != "quit") {
    if (str == "add") {
      int val;
      cin >> val;
      q.add(val);
    }
    else if (str == "remove") {
      int val = q.remove();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "peek") {
      int val = q.peek();
      if (val != -1) {
        cout << val << endl;
      }
    }
    else if (str == "size") {
      cout << q.size() << endl;
    }
    cin >> str;
  }
  return 0;
}