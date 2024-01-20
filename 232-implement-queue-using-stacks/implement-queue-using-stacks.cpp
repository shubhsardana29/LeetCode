class MyQueue {
public:
// method 2 in which push-> o(1),empty in o(1) , rest o(n)
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {  
        s1.push(x);
    }
    
int pop() {
        if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    if (!s2.empty()) {
        int popped = s2.top();
        s2.pop();
        return popped;
    } else {
        return -1; 
    }
}
    
   int peek() {
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    if (!s2.empty()) {
        return s2.top();
    } else {
        return -1; 
    }
}
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */