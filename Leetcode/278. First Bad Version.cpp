class Solution {
public:
    int firstBadVersion(int n) {
        int s=1,e=n;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(isBadVersion(mid)){
                e=mid-1;
            }
            else if(!isBadVersion(mid)){
                 s=mid+1;
            }
        }
        return s;
    }
};
