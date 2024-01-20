class MyStack {
public:
// method 2 using only 1 queue
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        // reverse loop till size-1
        for(int i=0;i<q.size()-1;i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
        
    }
    
    int pop() {
        if(q.empty()) return -1;
        int popped=q.front();
        q.pop();
        return popped;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */