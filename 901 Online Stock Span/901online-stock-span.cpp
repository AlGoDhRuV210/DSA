class StockSpanner {
public:
stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=0;
        while(!s.empty() && s.top().first<=price)
       {
        ans+=s.top().second;
        s.pop();
       }
       s.push({price,ans+1});
        return ans+1;

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */