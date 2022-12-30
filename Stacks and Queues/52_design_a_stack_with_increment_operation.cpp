class CustomStack {
public:
    vector<int>value;
    vector<int>Increment;
    int index;
    CustomStack(int maxSize) {
        value.resize(maxSize);
        Increment.resize(maxSize);
        index = -1;
    }
    
    void push(int x) {
        if(index + 1 == value.size()){
            return;
        }
        index++;
        value[index] = x;
        Increment[index] = 0;
    }
    
    int pop() {
        if(index == -1){
            return -1;
        }
        int x = value[index];
        int inc = Increment[index];
        index--;
        if(index >= 0){
            Increment[index] += inc;
        }
        return x + inc;
    }
    
    void increment(int k, int val) {
        int ind = min(k-1, index);
        if(index >= 0){
            Increment[ind] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */