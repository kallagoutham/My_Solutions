class Solution {
public:
    int countOperations(int num1, int num2) {
        int res=0,tmp;
        while(!(num1==0 || num2==0)){
            tmp=abs(num1-num2);
            num2=(num1>num2)?num2:num1;
            num1=tmp;
            // cout<<num1<<" "<<num2<<endl;
            res++;
        }
        return res;
    }
};
