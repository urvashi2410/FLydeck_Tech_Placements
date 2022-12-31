class MyCircularDeque {
private:
    const int k;
    vector<int>q;
    int size;
    int front;
    int rear;

public:
    MyCircularDeque(int k): k(k){
        size = 0;
        front = 0;
        rear = k-1;
        q.resize(k);
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }

        front = (--front + k) % k;
        q[front] = value;
        ++size;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }

        rear = ++rear % k;
        q[rear] = value;
        ++size;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }

        front = ++front % k;
        --size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }

        rear = (--rear + k) % k;
        --size;
        return true;
    } 
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */