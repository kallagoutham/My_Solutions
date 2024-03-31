class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0;
        int t=x;
        while(t>0){
            sum+=t%10;
            t/=10;
        }
        if(x%sum==0){return sum;}
        return -1;
    }
};
