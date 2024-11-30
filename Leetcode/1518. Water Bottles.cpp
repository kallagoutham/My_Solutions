class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int r=0;
        int ans=0;
        while(numBottles>=1){
            ans+=numBottles;
            int temp=numBottles;
            numBottles=(numBottles+r)/numExchange;
            r=(temp+r)%numExchange;
            
        }
        return ans;
    }
};
