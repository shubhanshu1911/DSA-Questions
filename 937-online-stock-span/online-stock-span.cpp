class StockSpanner {
public:
    vector<int> oldPrice;
    // int span = 1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        // push the price value in to the oldPrice vector 
        int span = 1;
        oldPrice.push_back(price);
        int i = oldPrice.size()-1;

        // First element
        if(i == 0){
            return span;
        }

        for(int j=i-1; j>=0; j--){
            if(oldPrice[i] >= oldPrice[j]){
                span++;
            }
            else{
                break;
            }
        }
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */