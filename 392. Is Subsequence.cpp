class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        int p1=0,p2=0;
        while(p1<m && p2<n){
            if(s[p1]==t[p2]){
                p1++;
                p2++;
            }
            else{
                p2++;
            }
        }
        if(p1==m){
            return true;
        }
        if(p2==n && p1==m){
            return true;
        }
        return false;
    }
};
