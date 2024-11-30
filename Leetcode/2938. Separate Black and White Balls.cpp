class Solution {
public:
    long long minimumSteps(string s) {
        long long res=0;
        int nz=0;
        for(char i:s){
            if(i=='0'){
                nz++;
            }
        }
        int n=s.size();
        int t=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                res+=(i-t);
                t++;
            }
            if(t>nz){break;}
        }
        return res;
    }

};
