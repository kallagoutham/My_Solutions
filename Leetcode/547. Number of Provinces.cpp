class Solution {
public:
    int res=0;
    void DFS(int src,vector<bool>& visited,vector<vector<int>>& isConnected){
        visited[src]=true;
        for(int i=0;i<isConnected[src].size();i++){
            if(isConnected[src][i]==1 && !visited[i]){
                visited[i]=true;
                DFS(i,visited,isConnected);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                DFS(i,visited,isConnected);
            }
        }
        return res;
    }
};


// Using Union Find Solution 

class UnionFind{
    private:
        vector<int> parent,rank;
    public:
        UnionFind(int size){
            rank.resize(size,0);
            parent.resize(size);
            for(int i=0;i<size;i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(node==parent[node]){return node;}
            return parent[node] = findParent(parent[node]);
        }
        void union_set(int x,int y){
            int ulp_x = findParent(x);
            int ulp_y = findParent(y);
            if(ulp_x == ulp_y){return;}
            if(rank[ulp_x] < rank[ulp_y]){
                parent[ulp_x] = ulp_y;
            }else if(rank[ulp_y] < rank[ulp_x]){
                parent[ulp_y] = ulp_x;
            }else{
                parent[ulp_y] = ulp_x;
                rank[ulp_x]++;
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind dsu(n);
        int numberOfComponents = n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] && dsu.findParent(i) != dsu.findParent(j)){
                    numberOfComponents--;
                    dsu.union_set(i,j);
                }
            }
        }
        return numberOfComponents;
    }
};
