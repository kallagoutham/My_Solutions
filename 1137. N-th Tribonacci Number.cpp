class Solution {
public:
    int tribonacci(int n) {
        int t0=0,t1=1,t2=1;
        if(n==0){return 0;}
        if(n==1){return 1;}
        if(n==2){return 1;}
        while(n>2){
            int temp = t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=temp;
            n--;
        }
        return t2;
    }
};
