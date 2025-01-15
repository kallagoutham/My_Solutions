class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int s1=0,s2=0;
        for(int i=0;i<32;i++){
            if((num1&(1<<i))!=0){
                s1++;
            }
            if((num2&(1<<i))!=0){
                s2++;
            }
        }
        int diff=0;
        if(s1==s2) return num1;
        if(s2>s1){
            diff=s2-s1;
            for(int i=0;i<32;i++){
                if((num1&(1<<i))==0){
                    num1=num1|(1<<i);
                    diff--;
                    if(diff==0) break;
                }
            }
            return num1;
        }
        num2=0;
        for(int i=31;i>=0;i--){
            if((num1&(1<<i))!=0){
                    num2=num2|(1<<i);
                    s2--;
                    if(s2==0) break;
            }
        }
        return num2;
    }
};
