class MinStack {
public:
stack<long long> s;
int minval=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()) {s.push(value);  minval=value;return;}
        if(value>minval) {s.push(value); return;}
        long long nw = 2LL*value - minval;
     
        s.push(nw);
        minval=value;
    }
    
    void pop() {
        if(s.top() >= minval)  {s.pop(); return;}
        minval=2LL*minval - s.top();
        s.pop();
         if(s.empty())  minval = INT_MAX;
    }
    
    int top() {
        if(s.top() > minval) return s.top();
        return minval;        
    }
    
    int getMin() {
        return minval;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */