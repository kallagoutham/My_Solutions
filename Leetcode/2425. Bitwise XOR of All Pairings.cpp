class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int xor1=0,xor2=0;
        for(int i:nums1){
            xor1^=i;
        }
        for(int i:nums2){
            xor2^=i;
        }
        if(((n1&1)==0) && ((n2&1)==0)){
            return 0;
        }else if(n1&1 && n2&1){
            return xor1^xor2;
        }
        if(n1&1)    return xor2;
        return xor1;
    }
};
