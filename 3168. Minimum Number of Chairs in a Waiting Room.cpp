class Solution {
public:
    int minimumChairs(string s) {
        int res=INT_MIN;
        int temp=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='E'){
                temp+=1;
                res=max(temp,res);
            }else{
                temp-=1;
            }
        }
        return res;
    }
};
