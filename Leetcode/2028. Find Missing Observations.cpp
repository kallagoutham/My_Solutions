class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(int i:rolls){
            sum+=i;
        }
        int m=rolls.size();
        int rs=(m+n)*mean;
        vector<int> res;
        if(((n*1) <=rs-sum) && ((rs-sum)<=n*6)){
            sum=rs-sum;
            res.assign(n,sum/n);
            rs=(sum) % n;
            for(int i=0;i<rs;++i){
                res[i]++;
            }
        }
        return res;
        
    }
};
