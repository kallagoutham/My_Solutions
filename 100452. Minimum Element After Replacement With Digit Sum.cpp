class Solution {
public:
    int sumOfDigits(int num){
        int sum=0;
        while(num){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int res=INT_MAX;
        for(int i:nums){
            res=min(res,sumOfDigits(i));
        }
        return res;
    }
};
