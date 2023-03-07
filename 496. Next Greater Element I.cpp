class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            auto pos=find(nums2.begin(),nums2.end(),nums1[i]);
            bool flag=false;
            if(pos!=nums2.end()){
                int idx=pos-nums2.begin();
                for(int j=idx;j<nums2.size();j++){
                    if(nums2[j]>nums1[i]){
                        res.push_back(nums2[j]);
                        flag=true;
                        break;
                    }
                }
            }
            else{
                res.push_back(-1);
            }
            if(!flag){
                res.push_back(-1);
            }
        }
        return res;
    }
};
