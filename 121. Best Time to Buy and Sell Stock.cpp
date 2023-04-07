//T(N)=O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_value=INT_MAX;
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_value){
                min_value=prices[i];
            }
            else if(max_profit<prices[i]-min_value){
                max_profit=prices[i]-min_value;
            }
        }
        return max_profit;
    }
};
/*--------------------------------------------------------------------------------------------------------------*/
//T(N)=O(N*N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int days=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                if((prices[j]-prices[i])>profit){
                    profit=prices[j]-prices[i];
                }
            }
        }
        return profit;
    }
};
