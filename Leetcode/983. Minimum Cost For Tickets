class Solution {
public:
    int solve(vector<int>&dp,vector<int>& days,vector<int>& costs,int pos,int reachability){
        if(pos>=days.size()) return 0;
        if(reachability>=days[pos]) return solve(dp,days,costs,pos+1,reachability);
        if(dp[pos]!=-1) return dp[pos];
        vector<int> pass;
        pass.push_back(costs[0]+solve(dp,days,costs,pos+1,days[pos]));
        pass.push_back(costs[1]+solve(dp,days,costs,pos+1,days[pos]+6));
        pass.push_back(costs[2]+solve(dp,days,costs,pos+1,days[pos]+29));
        return dp[pos]=*min_element(pass.begin(),pass.end());
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(365,-1);
       return min({
        costs[0] + solve(dp, days, costs, 0, days[0]),
        costs[1] + solve(dp, days, costs, 0, days[0] + 6),
        costs[2] + solve(dp, days, costs, 0, days[0] + 29)
});

    }
};
