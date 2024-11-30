class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r;
        int i=0;
        while(i<32){
            r<<=1;
            if((n&1)==1){
                r^=1;
            }
            n>>=1;
            i++;
        }
        return r;
    }
};
