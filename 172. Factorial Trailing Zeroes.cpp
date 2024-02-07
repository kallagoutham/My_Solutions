class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0,t =5;
        while(n>=t){ans+= n/t;t*=5;}
        return ans;
    }
};
