class MyQueue {
public:
    stack<int> st;
    
    MyQueue() {
        
    }
    void insertAtBottom(stack<int>& st, int target){
        if(st.empty()){
            st.push(target);
            return;
        }

        int topElement = st.top();
        st.pop();

        insertAtBottom(st, target);

        st.push(topElement);
    }

    void push(int x) {
       if(st.empty()){
        st.push(x);
        return;
       }
       st.push(x);
       int target = st.top();
       st.pop();
       insertAtBottom(st,target);
       
       return;
    }
    
    int pop() {
        int popElement = st.top();
        st.pop();

        return popElement;
    }
    
    int peek() {
       return st.top(); 
    }
    
    bool empty() {
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
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