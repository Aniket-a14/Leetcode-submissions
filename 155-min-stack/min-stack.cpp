class MinStack {
public:
    stack<int> ele,minm;
    MinStack() {
        
    }
    
    void push(int val) {
        ele.push(val);
        if(minm.empty()) minm.push(val);
        else minm.push(min(val,minm.top()));
    }
    
    void pop() {
        ele.pop(); minm.pop();
    }
    
    int top() {
        return ele.top();
    }
    
    int getMin() {
        return minm.top();
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