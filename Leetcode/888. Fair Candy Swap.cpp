class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int as=0,bs=0;
        for(int i=0;i<aliceSizes.size();i++){
            as+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.size();i++){
            bs+=bobSizes[i];
        }
        vector<int> res;
        for(int i=0;i<aliceSizes.size();i++){
            for(int j=0;j<bobSizes.size();j++){
                if(as-aliceSizes[i]+bobSizes[j] == bs-bobSizes[j]+aliceSizes[i]){
                    res.push_back(aliceSizes[i]);
                    res.push_back(bobSizes[j]);
                    return res;
                }
            }
        }
        return res;
    }
};
