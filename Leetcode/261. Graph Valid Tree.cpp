class DisjointSet{
    private:
        vector<int> parent,size;
    
    public:
        DisjointSet(int s){
            size.resize(s,1);
            parent.resize(s);
            for(int i=0;i<s;i++){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]){return node;}
            return parent[node] = findUPar(parent[node]);
        }

        void UnionBySize(int x,int y){
            int ulp_x = findUPar(x);
            int ulp_y = findUPar(y);
            if(ulp_x == ulp_y){return;}
            if(size[ulp_x] < size[ulp_y]){
                parent[ulp_x] = ulp_y;
                size[ulp_y] += size[ulp_x];
            }else{
                parent[ulp_y] = ulp_x;
                size[ulp_x] += size[ulp_y];
            }
        }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }
        DisjointSet ds(n);
        for(vector<int> edge:edges){
            int x = edge[0];
            int y = edge[1];
            if(ds.findUPar(x)==ds.findUPar(y)){
                return false;
            }
            ds.UnionBySize(x,y);
        }
        return true;
    }
};
