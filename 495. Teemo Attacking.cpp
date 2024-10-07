class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int attackTime=timeSeries[0];
        int currentPastTime=timeSeries[0]+duration;
        int res=duration;
        for(int i=1;i<timeSeries.size();++i){
            if(timeSeries[i]<=currentPastTime){
                res+=(timeSeries[i]+duration-currentPastTime);
            }else{
                res+=duration;
            }
            currentPastTime=timeSeries[i]+duration;
        }
        return res;
    }
};
