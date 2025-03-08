class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0,j=k-1,count=0,n=blocks.size();
        for(int p=0;p<k;p++){
            if(blocks[p]=='W')  count++;
        }
        int res=count;
        while(j<n-1){
            j++;
            if(blocks[j]=='W')  count++;
            if(blocks[i]=='W')  count--;
            i++;
            res=min(res,count);
        }
        return res;
    }
};
