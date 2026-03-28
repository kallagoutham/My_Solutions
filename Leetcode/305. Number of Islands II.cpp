class DisjointSetUnion{
    private:
        vector<int> parent, rank, size;
    
    public:
        DisjointSetUnion(int n){
            size.resize(n,1);
            rank.resize(n,0);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]){return node;}
            return parent[node] = findUPar(parent[node]);
        }

        void UnionBySize(int x, int y){
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

        void UnionByRank(int x, int y){
            int ulp_x = findUPar(x);
            int ulp_y = findUPar(y);
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
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,-1,0,1};

    bool isValid(int r, int c, int m, int n){
        return (r >=0 && r < m && c >= 0 && c< n);
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        int count = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        DisjointSetUnion ds(m*n);
        
        for(vector<int> position:positions){
            int row = position[0];
            int col = position[1];
            if(visited[row][col]){
                res.push_back(count);
                continue;
            }
            visited[row][col]=true;
            count++;
            for(int i=0;i<4;i++){
                int adjr = row + dx[i];
                int adjc = col + dy[i];
                if(isValid(adjr,adjc,m,n)){
                    if(visited[adjr][adjc]){
                        int node = row  * n + col;
                        int adjNode = adjr * n + adjc;
                        if(ds.findUPar(node) != ds.findUPar(adjNode)){
                            count--;
                            ds.UnionBySize(node,adjNode);
                        }
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
