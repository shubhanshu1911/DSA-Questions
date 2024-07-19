class StockSpanner {
public:
    StockSpanner() {
        // No initialization required here as we will use class members
    }
    
    int next(int price) {
        int span = 1;
        // Pop elements from the stack as long as the stack is not empty
        // and the price at the top of the stack is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push the current price and its span onto the stack
        st.push({price, span});
        
        return span;
    }

private:
    stack<pair<int, int>> st; // Pair of {price, span}
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */