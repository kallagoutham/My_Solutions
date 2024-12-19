class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre =arr;
        vector<int> suf = arr;
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],pre[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=min(suf[i+1],suf[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(i==0||suf[i]>pre[i-1]){res++;}
        }
        return res;
        
    }
};
