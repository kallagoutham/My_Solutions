class Solution {
public:
    int productOfDigits(int n){
        int res=1;
        while(n){
            res *= n%10;
            n /= 10;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        while(n<INT_MAX){
            if(productOfDigits(n)%t == 0){
                return n;
            }
            n++;
        }
        return -1;
    }
};
