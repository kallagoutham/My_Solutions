class Solution {
public:
    int numSub(string s) {
        int res=0,mod=1000000007;
        int temp=0,l=0,r=0,n=s.size();
        while(l<=r && r<n){
            temp=0;
            while(s[r]=='1'){
                r++;
                temp=(temp+1) % mod;
            }
            while(l<r){
                res=((res%mod)+(temp%mod))%mod;
                temp= (temp-1)%mod;
                l++;
            }
            r++;
        }
        return res;
    }
};
