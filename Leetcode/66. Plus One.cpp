class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size(),i;
        for(i=n-1;i>=0;i--){
            if(digits[i]!=9){
                digits[i]+=1;
                break;
            }
        }
        replace(digits.begin()+i+1,digits.end(),9,0);
        if(i==-1){
            digits.insert(digits.begin(),1);
            replace(digits.begin(),digits.end(),9,0);
        }
        return digits;
    }
};
