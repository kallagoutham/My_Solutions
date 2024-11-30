class Solution {
public:
    string convertToBase7(int num) {
        string res;
        bool neg=false;
        if(num==0){return "0";}
        if(num<0){num*=-1;neg=true;}
        while(num>0){
            res.push_back(char(num%7 +48));
            num=num/7;
        }
        if(neg){
            res.push_back('-');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
