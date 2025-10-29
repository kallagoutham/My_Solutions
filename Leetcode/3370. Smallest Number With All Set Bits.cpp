class Solution {
public:
    int smallestNumber(int n) {
        int res=1,num=0;
        while(n>0){
            res= res | (1<<num);
            num++;
            n=n>>1;
        }
        return res;
    }
};
