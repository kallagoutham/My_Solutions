class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> res(n,0);
        int r=0,l=(boxes[0]=='1')?1:0;
        for(int i=1;i<n;i++){
            if(boxes[i]=='1'){
                res[0]+=i;
                r++;
            }
        }
        for(int i=1;i<n;i++){
            res[i]=res[i-1]+l-r;
            if(boxes[i]=='1'){
                l++;
                r--;
            }
        }
        return res;
    }
};
