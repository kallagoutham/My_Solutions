class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n+1);
        res[1]=1;
        int t2=1,t3=1,t5=1;
        for(int i=2;i<=n;i++){
            int first=res[t2]*2;
            int second=res[t3]*3;
            int third=res[t5]*5;
            res[i]=min({first,second,third});
            if(res[i]==first){t2++;}
            if(res[i]==second){t3++;}
            if(res[i]==third){t5++;}
        }
        return res[n];
    }
};
