class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int res=0;
        for(int i=1;i<n;++i){
            res+=(abs(s[i]-s[i-1]));
        }
        return res;
    }
};
