class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(), greater<int>());
        int i=0, n=cost.size();
        int res = 0;
        while(i+2 < n){
            res += (cost[i] + cost[i+1]);
            i = i + 3;
        }
        if(i < n){
            res += cost[i];
        }
        if(i+1 < n){
            res += cost[i+1];
        }
        return res;
    }
};
