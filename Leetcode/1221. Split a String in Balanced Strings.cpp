class Solution {
public:
    int balancedStringSplit(string s) {
        int cl=0,cr=0,res=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L'){cl++;}
            else{cr++;}
            if(cl==cr){
                res++;
                cl=0;
                cr=0;
            }
        }
        return res;
    }
};
