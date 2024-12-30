class Solution {
public:
    int MOD=1000000007;
    int count(vector<int>& dp,int& low,int& high,int& zero,int& one,int currentLength){
        if(currentLength>high){return 0;}
        if(dp[currentLength]!=-1){return dp[currentLength];}
        int cnt=0;
        if(currentLength>=low){cnt++;}
        cnt+=count(dp,low,high,zero,one,currentLength+zero);
        cnt+=count(dp,low,high,zero,one,currentLength+one);
        return dp[currentLength]=cnt%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(100001,-1);
        return count(dp,low,high,zero,one,0);
    }
};
