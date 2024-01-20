class MyQueue {
public:
// method 1 in which push-> o(n) , rest o(1)
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int copy1=s1.top();  //copy from s1
            s2.push(copy1);      // paste in s2
            s1.pop();            // cut from s1
        } 
        s1.push(x);
        while(!s2.empty()){
            int copy2=s2.top();
            s1.push(copy2);
            s2.pop();
        }
    }
    
    int pop() {
        if (s1.empty()) {
            return -1; 
        }
        int popped=s1.top();
        s1.pop();
        return popped;
    }
    
    int peek() {
        if (s1.empty()) {    
            return -1; 
        }
        int front=s1.top();
        return front;
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