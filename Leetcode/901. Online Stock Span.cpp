class StockSpanner {
public:
    stack<pair<int,int>> st;
    int idx = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res;
        if(st.size()==0){
            res = 1;
        }
        if(st.size()!=0 && st.top().first > price){
            res = 1;
        }else if(st.size()!=0 && st.top().first <= price){
            while(st.size()!=0 && st.top().first <= price){
                st.pop();
            }
            if(st.empty()){
                res = idx+1;
            }else{
                res = idx - st.top().second;
            }
        }
        st.push({price,idx++});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
