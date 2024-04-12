class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> l(n);
        fill(l.begin(),l.end(),height[0]);
        vector<int> r(n);
        fill(r.begin(),r.end(),height[n-1]);
        
        for(int i=1;i<n;i++){
            l[i]=max(height[i],l[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            r[i]=max(height[i],r[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(l[i],r[i])-height[i];
        }
        return ans;
    }
};
