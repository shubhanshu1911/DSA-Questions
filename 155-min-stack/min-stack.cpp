class MinStack {
public:
    vector <pair <int, int> > v;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()){
            // make_pair is a STL function to make pair (first, second)
            pair <int, int> p = make_pair(val, val);
            v.push_back(p);
        }
        else{
            pair <int, int> p;
            p.first = val;
            p.second = min(val, v.back().second);
            v.push_back(p);
        }
        
    }
    
    void pop() {
        v.pop_back();
        
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
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