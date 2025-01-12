class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if (n%2!=0) return false;
        int o=0,f=0;
        for (int i=0;i<n;i++) {
            if (locked[i]=='1') {
                if (s[i]=='(') o++;
                else o--;
            } else {
                f++;
            }
            if (o+f<0) return false;
        }
        o=0,f=0;
        for (int i=n-1;i>=0;i--) {
            if (locked[i]=='1') {
                if (s[i]==')') o++;
                else o--;
            } else {
                f++;
            }
            if (o+f<0) return false;
        }
        return true;
    }
};
