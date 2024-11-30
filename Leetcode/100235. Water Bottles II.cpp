class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res=numBottles;
        int emptybottles=numBottles;
        while(emptybottles>=numExchange){
            emptybottles-=numExchange;
            numExchange++;
            emptybottles++;
            res++;
        }
        return res;
    }
};
