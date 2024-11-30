class Solution {
public:
    int count(int n){
        int res=0;
        while(n>0){
            n=n&n-1;
            res++;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;++i){
            res.push_back(count(i));
        }
        return res;
    }
};
