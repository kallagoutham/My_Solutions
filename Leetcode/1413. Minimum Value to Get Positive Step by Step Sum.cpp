class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = INT_MAX, t=0;
        for(int i:nums){
            t += i;
            res = min(t,res);
        };
        return (res > 0) ? 1 : abs(res)+1 ;
    }
};
