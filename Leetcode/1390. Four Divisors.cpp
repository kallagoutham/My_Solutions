class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int count=0,res=0,temp=0;
        for(int n:nums){
            count=0;
            temp=0;
            for(int i=1;i<=sqrt(n);i++){
                if(n%i == 0){
                    count+=2;
                    if(i==sqrt(n)){
                        count-=1;
                    }
                    temp=temp+(n/i)+i;
                }
            }
            if(count==4){
                res+=temp;
            }
        }
        return res;
    }
};
