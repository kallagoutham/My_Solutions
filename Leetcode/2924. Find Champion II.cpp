class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> v(n,0);
        for(vector<int>& edge:edges){
            v[edge[1]]++;
        }
        int res=-1;
        int c=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                res=i;
                c++;
            }
        }
        if(c!=1){
            return -1;
        }
        return res;
    }
};
