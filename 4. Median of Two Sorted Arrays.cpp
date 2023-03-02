class Solution {
public:
    double find(vector<int>&a1,int n, vector<int>&a2,int m){
        if(n>m) return find(a2,m,a1,n);
        int l=0,r=n;
        int fmid=(n+m+1)/2;
        while(l<=r){
            int c1=(l+r)/2;
            int c2=fmid-c1;
            int l1=(c1==0)?INT_MIN:a1[c1-1];
            int l2=(c2==0)?INT_MIN:a2[c2-1];
            int r1=(c1==n)?INT_MAX:a1[c1];
            int r2=(c2==m)?INT_MAX:a2[c2];
            if(l1<=r2&&l2<=r1){
                if((m+n)%2==1){
                    return max(l1,l2);
                }
                else{
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1>r2)
                r=c1-1;
            else
                l=c1+1;
        }
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>&a1, vector<int>&a2) {
        int n=a1.size();
        int m=a2.size();
        return find(a1,n,a2,m);
    }
};
