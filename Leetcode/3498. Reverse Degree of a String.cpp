class Solution {
public:
    int reverseDegree(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            int t=s[i]-'a';
            res+=((26-t) * (i+1));
        }
        return res;
    }
};
