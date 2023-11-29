class MinStack {
public:
    vector<pair<int,int>>st;

    MinStack() {
        
    }

    int MinTillNow(int val){
        int prevMin = st.back().second;
        return min(prevMin,val);
    }
    
    void push(int val) {
        if(st.empty()){
            // it means we are inserting first element
            pair<int,int>p;
            p.first=val;
            p.second=val;
            st.push_back(p);
        }
        else{
            pair<int,int>p;
            p.first=val;
            p.second=MinTillNow(p.first);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int,int>RightMostPair=st.back();
        return RightMostPair.first;
    }
    
    int getMin() {
        pair<int,int>RightMostPair=st.back();
        return RightMostPair.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */