class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xr=0;
        for(int i:derived){
            xr^=i;
        }
        return xr==0?true:false;
    }
};
