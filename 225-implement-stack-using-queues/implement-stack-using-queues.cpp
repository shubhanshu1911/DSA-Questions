class MyStack {
public:
    deque <int> dq;
    MyStack() {
        
    }
    
    void push(int x) {
       if(dq.empty()){
        dq.push_back(x);
        return;
       } 

       dq.push_front(x);
       return;
    }
    
    int pop() {
        int popElement = dq.front();
        dq.pop_front();

        return popElement;
    }
    
    int top() {
       return dq.front(); 
    }
    
    bool empty() {
        if(dq.empty()){
            return true;
        }
        else{
            return false;
        }
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