class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res=0;
        while(start>0 || goal>0){
            res+=((start&1)^(goal&1));
            start>>=1;
            goal>>=1;
        }
        return res;
    }
};
