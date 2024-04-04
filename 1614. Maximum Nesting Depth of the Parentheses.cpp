class Solution {
public:
    int maxDepth(string s) {
        int res=0,t=0;
        for(char i:s){
            if(i=='('){
                t++;
                res=max(t,res);
            }
            if(i==')'){
                t--;
                res=max(t,res);
            }
        }
        return res;
    }
};
