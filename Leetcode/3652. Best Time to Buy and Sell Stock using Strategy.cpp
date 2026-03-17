class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long res=INT_MIN;
        int i=0,n=strategy.size();
        long long currentProfit=0,strategicProfit=0;
        for(i=0;i<k;i++){
            currentProfit += strategy[i]*prices[i];
            if(i>=k/2){strategicProfit += prices[i];}
        }
        res = max(res,strategicProfit - currentProfit);
        int j=0;
        long long realProfit = currentProfit;
        while(i<n){
            currentProfit -= (strategy[j] * prices[j]);
            currentProfit += (strategy[i] * prices[i]);
            realProfit += (strategy[i] * prices[i]);
            strategicProfit += prices[i];
            strategicProfit -= prices[j+k/2];
            res = max(res,strategicProfit - currentProfit);
            i++;
            j++;
        }
        return res > 0 ? realProfit + res : realProfit;
    }
};
